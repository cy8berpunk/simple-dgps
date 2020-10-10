// Generated by commsdsl2comms v3.5.2

/// @file
/// @brief Contains definition of <b>"LOG-CREATE"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include <type_traits>
#include "comms/MessageBase.h"
#include "comms/field/BitmaskValue.h"
#include "comms/field/EnumValue.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "ublox/MsgId.h"
#include "ublox/field/FieldBase.h"
#include "ublox/field/Res1.h"
#include "ublox/message/LogCreateCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace message
{

/// @brief Fields of @ref LogCreate.
/// @tparam TOpt Extra options
/// @see @ref LogCreate
/// @headerfile "ublox/message/LogCreate.h"
template <typename TOpt = ublox::options::DefaultOptions>
struct LogCreateFields
{
    /// @brief Definition of <b>"version"</b> field.
    struct Version : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t,
            comms::option::def::ValidNumValue<0>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::LogCreateFieldsCommon::VersionCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"logCfg"</b> field.
    class LogCfg : public
        comms::field::BitmaskValue<
            ublox::field::FieldBase<>,
            comms::option::def::FixedLength<1U>,
            comms::option::def::BitmaskReservedBits<0xFEU, 0x0U>
        >
    {
        using Base = 
            comms::field::BitmaskValue<
                ublox::field::FieldBase<>,
                comms::option::def::FixedLength<1U>,
                comms::option::def::BitmaskReservedBits<0xFEU, 0x0U>
            >;
    public:
        /// @brief Provides names and generates access functions for internal bits.
        /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
        ///     related to @b comms::field::BitmaskValue class from COMMS library
        ///     for details.
        ///
        ///      The generated enum values and functions are:
        ///      @li @b BitIdx_logCfg, @b getBitValue_logCfg() and @b setBitValue_logCfg().
        COMMS_BITMASK_BITS_SEQ(
            logCfg
        );
        
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::LogCreateFieldsCommon::LogCfgCommon::name();
        }
        
        /// @brief Retrieve name of the bit.
        static const char* bitName(BitIdx idx)
        {
            return
                ublox::message::LogCreateFieldsCommon::LogCfgCommon::bitName(
                    static_cast<std::size_t>(idx));
        }
        
    };
    
    /// @brief Definition of <b>"reserved1"</b> field.
    struct Reserved1 : public
        ublox::field::Res1<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::LogCreateFieldsCommon::Reserved1Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"logSize"</b> field.
    /// @see @ref ublox::message::LogCreateFieldsCommon::LogSizeVal
    class LogSize : public
        comms::field::EnumValue<
            ublox::field::FieldBase<>,
            ublox::message::LogCreateFieldsCommon::LogSizeVal,
            comms::option::def::ValidNumValueRange<0, 2>
        >
    {
        using Base = 
            comms::field::EnumValue<
                ublox::field::FieldBase<>,
                ublox::message::LogCreateFieldsCommon::LogSizeVal,
                comms::option::def::ValidNumValueRange<0, 2>
            >;
    public:
        /// @brief Re-definition of the value type.
        using ValueType = typename Base::ValueType;
    
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::LogCreateFieldsCommon::LogSizeCommon::name();
        }
        
        /// @brief Retrieve name of the enum value
        static const char* valueName(ValueType val)
        {
            return ublox::message::LogCreateFieldsCommon::LogSizeCommon::valueName(val);
        }
        
        /// @brief Retrieve name of the @b current value
        const char* valueName() const
        {
            return valueName(Base::value());
        }
        
    };
    
    /// @brief Definition of <b>"userDefinedSize"</b> field.
    struct UserDefinedSize : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint32_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::LogCreateFieldsCommon::UserDefinedSizeCommon::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Version,
        LogCfg,
        Reserved1,
        LogSize,
        UserDefinedSize
    >;
};

/// @brief Definition of <b>"LOG-CREATE"</b> message class.
/// @details
///     See @ref LogCreateFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "ublox/message/LogCreate.h"
template <typename TMsgBase, typename TOpt = ublox::options::DefaultOptions>
class LogCreate : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::LogCreate,
        comms::option::def::StaticNumIdImpl<ublox::MsgId_LogCreate>,
        comms::option::def::FieldsImpl<typename LogCreateFields<TOpt>::All>,
        comms::option::def::MsgType<LogCreate<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::LogCreate,
            comms::option::def::StaticNumIdImpl<ublox::MsgId_LogCreate>,
            comms::option::def::FieldsImpl<typename LogCreateFields<TOpt>::All>,
            comms::option::def::MsgType<LogCreate<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_version type and @b field_version() access fuction
    ///         for @ref LogCreateFields::Version field.
    ///     @li @b Field_logCfg type and @b field_logCfg() access fuction
    ///         for @ref LogCreateFields::LogCfg field.
    ///     @li @b Field_reserved1 type and @b field_reserved1() access fuction
    ///         for @ref LogCreateFields::Reserved1 field.
    ///     @li @b Field_logSize type and @b field_logSize() access fuction
    ///         for @ref LogCreateFields::LogSize field.
    ///     @li @b Field_userDefinedSize type and @b field_userDefinedSize() access fuction
    ///         for @ref LogCreateFields::UserDefinedSize field.
    COMMS_MSG_FIELDS_NAMES(
        version,
        logCfg,
        reserved1,
        logSize,
        userDefinedSize
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 8U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 8U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return ublox::message::LogCreateCommon::name();
    }
    
    
};

} // namespace message

} // namespace ublox

