#include "gpsCore.h"

static double calcTimeFromEpoch(double t, double t_ref) 
{
  t-= t_ref;
  if      (t> 302400) t -= 604800;
  else if (t<-302400) t += 604800;
  return t;
}

static double calcEccentricAnomaly(ephemeris *ephem, double t_k) 
{
  // Semi-major axis
  int A = ephem->sqrtA*ephem->sqrtA;

  // Computed mean motion (rad/sec)
  double n_0 = sqrt(ephem->MU/(ephem->A*ephem->A*ephem->A));

  // Corrected mean motion
  double n = n_0 + ephem->dn;

  // Mean anomaly
  double M_k = ephem->M_0 + n*t_k;

  // Solve Kepler's Equation for Eccentric Anomaly
  double E_k = M_k;
  for(;;) 
  {
      double temp = E_k;
      E_k = M_k + ephem->e*sin(E_k);
      if (fabs(E_k - temp) < 1e-10) break;
  }

  return E_k;
}

//  Convert Earth-Centered-Earth-Fixed (ECEF) to lat, Lon, Altitude
static latLonAltPos ecefToLatLonAlt(ecefPos ecef)
{
  latLonAltPos finalLatLonPos = { 0, 0, 0 };
  double zp, w2, w, r2, r, s2, c2, s, c, ss;
  double g, rg, rf, u, v, m, f, p, x, y, z; 
  double n, lat, lon, alt;

  x = ecef.x;
  y = ecef.y;
  z = ecef.z;

  zp = abs(z);
  w2 = x*x + y*y;
  w = sqrt(w2);
  
  r2 = w2 + z*z;
  r = sqrt(r2);
  finalLatLonPos.lon = atan2(y, x);

  s2 = z*z/r2;
  c2 = w2/r2;
  u = A2/r;
  v = A3 - A4/r;

  if(c2 > 0.3)
  {
    s = (zp/r)*(1.0 + c2*(A1 + u + s2*v)/r);
    finalLatLonPos.lat = asin(s);
    ss = s*s;
    c = sqrt(1.0 - ss);
  } else
  {
    c = (w/r)*(1.0 - s2*( A5 - u - c2*v )/r);
    finalLatLonPos.lat = acos(c);
    ss = 1.0 - c*c;
    s = sqrt(ss);
  }
  g = 1.0 - E2*ss;
  rg = A/sqrt(g);
  rf = A6*rg;
  u = w - rg*c;
  v = zp - rf*s;
  f = c*u + s*v;
  m = c*v - s*u;
  p = m/( rf/g + f );

  finalLatLonPos.lat = finalLatLonPos.lat + p;
  finalLatLonPos.alt = f + m*p/2.0;
  if(z < 0.0)
  {
      finalLatLonPos.lat *= -1.0;
  }
  return finalLatLonPos;
}

// Convert Lat, Lon, Altitude to Earth-Centered-Earth-Fixed (ECEF)
static ecefPos latLonAltToEcef(latLonAltPos latlonAlt)
{
  double zp, w2, w, r2, r, s2, c2, s, c, ss;
  double g, rg, rf, u, v, m, f, p, x, y, z; 
  double n, lat, lon, alt;

  ecefPos ecef = { 0, 0, 0 };

  lat = latlonAlt.lat;
  lon = latlonAlt.lon;
  alt = latlonAlt.alt;

  n = A/sqrt(1 - E2 * sin(lat)* sin(lat));

  ecef.x = (n + alt )* cos(lat)* cos(lon);
  ecef.y = (n + alt )* cos(lat)* sin(lon);
  ecef.z = (n*(1 - E2 ) + alt)* sin(lat);

  return ecef;
}

// static satRanges calcTrueRange(ecefPos satPos, latLonAltPos baseStationPos) 
// {

// }

static ecefPos calcSatPos(ephemeris *ephem, double t) 
{ // Get satellite position at time t
  // Time from ephemeris reference epoch
  double t_k = calcTimeFromEpoch(t, ephem->t_oe);

  // Eccentric Anomaly
  double E_k = calcEccentricAnomaly(ephem, t_k);

  // True Anomaly
  double v_k = atan2(
    sqrt(1-ephem->e*ephem->e) * sin(E_k),
    cos(E_k) - ephem->e);

  // Argument of Latitude
  double AOL = v_k + ephem->omega;

  // Second Harmonic Perturbations
  double du_k = ephem->C_us*sin(2*AOL) + ephem->C_uc*cos(2*AOL);    // Argument of Latitude Correction
  double dr_k = ephem->C_rs*sin(2*AOL) + ephem->C_rc*cos(2*AOL);    // Radius Correction
  double di_k = ephem->C_is*sin(2*AOL) + ephem->C_ic*cos(2*AOL);    // Inclination Correction

  // Corrected Argument of Latitude; Radius & Inclination
  double u_k = AOL + du_k;
  double r_k = ephem->A*(1-ephem->e*cos(E_k)) + dr_k;
  double i_k = ephem->i_0 + di_k + ephem->IDOT*t_k;

  // Positions in orbital plane
  double x_kp = r_k*cos(u_k);
  double y_kp = r_k*sin(u_k);

  // Corrected longitude of ascending node
  double OMEGA_k = ephem->OMEGA_0 + (ephem->OMEGA_dot-ephem->OMEGA_E)*t_k - ephem->OMEGA_E*ephem->t_oe;

  ecefPos satPos = { 0, 0, 0 };

  // Earth-fixed coordinates
  satPos.x = x_kp*cos(OMEGA_k) - y_kp*cos(i_k)*sin(OMEGA_k);
  satPos.y = x_kp*sin(OMEGA_k) + y_kp*cos(i_k)*cos(OMEGA_k);
  satPos.z = y_kp*sin(i_k);

  return satPos;
}

static satRanges calcSatRangeCorrection(satRanges trueRanges, satRanges pseudoRanges) 
{
  // Declaring iterator to a vector 
  std::map<int, double>::iterator it; 
  std::map<int, double>::iterator trueRangeMap, pseudoRangeMap;
  satRanges rangeCorrection;
  for ( it = trueRanges.ranges.begin(); it != trueRanges.ranges.end(); it++ )
  {
    trueRangeMap = trueRanges.ranges.find(it->first);
    pseudoRangeMap = pseudoRanges.ranges.find(it->first);


    if (trueRangeMap != trueRanges.ranges.end() && pseudoRangeMap != pseudoRanges.ranges.end()) 
    {
      double correction = abs(trueRangeMap->second-pseudoRangeMap->second);
      rangeCorrection.ranges.insert(std::pair<int, double>(it->first, correction));
    }
  }
  return rangeCorrection;
}