// Generated by commsdsl2comms v3.5.2

#pragma once

#include <QtCore/QObject>
#include <QtCore/QtPlugin>
#include "comms_champion/Plugin.h"
#include "comms_champion/Protocol.h"

namespace ublox
{

namespace cc_plugin
{

namespace plugin
{

class UbloxPlugin : public comms_champion::Plugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "ublox" FILE "UbloxPlugin.json")
    Q_INTERFACES(comms_champion::Plugin)

public:
    UbloxPlugin();
    virtual ~UbloxPlugin();
private:
    comms_champion::ProtocolPtr m_protocol;
};

} // namespace plugin

} // namespace cc_plugin

} // namespace ublox

