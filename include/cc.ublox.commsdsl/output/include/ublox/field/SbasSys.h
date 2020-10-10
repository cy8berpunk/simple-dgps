// Generated by commsdsl2comms v3.5.2

/// @file
/// @brief Contains definition of <b>"sbasSys"</b> field.

#pragma once

#include <algorithm>
#include <cstdint>
#include <iterator>
#include <utility>
#include "comms/field/EnumValue.h"
#include "comms/options.h"
#include "ublox/field/FieldBase.h"
#include "ublox/field/SbasSysCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace field
{

/// @brief Definition of <b>"sbasSys"</b> field.
/// @see @ref ublox::field::SbasSysVal
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = ublox::options::DefaultOptions, typename... TExtraOpts>
class SbasSys : public
    comms::field::EnumValue<
        ublox::field::FieldBase<>,
        ublox::field::SbasSysVal,
        TExtraOpts...,
        comms::option::def::ValidNumValueRange<-1, 3>,
        comms::option::def::ValidNumValue<16>
    >
{
    using Base = 
        comms::field::EnumValue<
            ublox::field::FieldBase<>,
            ublox::field::SbasSysVal,
            TExtraOpts...,
            comms::option::def::ValidNumValueRange<-1, 3>,
            comms::option::def::ValidNumValue<16>
        >;
public:
    /// @brief Re-definition of the value type.
    using ValueType = typename Base::ValueType;

    /// @brief Name of the field.
    static const char* name()
    {
        return ublox::field::SbasSysCommon::name();
    }
    
    /// @brief Retrieve name of the enum value
    static const char* valueName(ValueType val)
    {
        return ublox::field::SbasSysCommon::valueName(val);
    }
    
    /// @brief Retrieve name of the @b current value
    const char* valueName() const
    {
        return valueName(Base::value());
    }
    
};

} // namespace field

} // namespace ublox

