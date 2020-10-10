// Generated by commsdsl2comms v3.5.2

/// @file
/// @brief Contains definition of <b>"CFG-PRT (USB)"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "ublox/MsgId.h"
#include "ublox/field/CfgPrtFlags.h"
#include "ublox/field/CfgPrtInProtoMask.h"
#include "ublox/field/CfgPrtOutProtoMask.h"
#include "ublox/field/CfgPrtTxReady.h"
#include "ublox/field/FieldBase.h"
#include "ublox/field/Res1.h"
#include "ublox/field/Res2.h"
#include "ublox/field/Res8.h"
#include "ublox/message/CfgPrtUsbCommon.h"
#include "ublox/options/DefaultOptions.h"

namespace ublox
{

namespace message
{

/// @brief Fields of @ref CfgPrtUsb.
/// @tparam TOpt Extra options
/// @see @ref CfgPrtUsb
/// @headerfile "ublox/message/CfgPrtUsb.h"
template <typename TOpt = ublox::options::DefaultOptions>
struct CfgPrtUsbFields
{
    /// @brief Definition of <b>"portId"</b> field.
    struct PortId : public
        comms::field::IntValue<
            ublox::field::FieldBase<>,
            std::uint8_t,
            comms::option::def::FailOnInvalid<>,
            comms::option::def::DefaultNumValue<3>,
            comms::option::def::ValidNumValue<3>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgPrtUsbFieldsCommon::PortIdCommon::name();
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
            return ublox::message::CfgPrtUsbFieldsCommon::Reserved1Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"txReady"</b> field.
    struct TxReady : public
        ublox::field::CfgPrtTxReady<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgPrtUsbFieldsCommon::TxReadyCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"reserved2"</b> field.
    struct Reserved2 : public
        ublox::field::Res8<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgPrtUsbFieldsCommon::Reserved2Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"inProtoMask"</b> field.
    struct InProtoMask : public
        ublox::field::CfgPrtInProtoMask<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgPrtUsbFieldsCommon::InProtoMaskCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"outProtoMask"</b> field.
    struct OutProtoMask : public
        ublox::field::CfgPrtOutProtoMask<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgPrtUsbFieldsCommon::OutProtoMaskCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"cfgPrtFlags"</b> field.
    using CfgPrtFlags =
        ublox::field::CfgPrtFlags<
            TOpt
        >;
    
    /// @brief Definition of <b>"reserved3"</b> field.
    struct Reserved3 : public
        ublox::field::Res2<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgPrtUsbFieldsCommon::Reserved3Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"reserved4"</b> field.
    struct Reserved4 : public
        ublox::field::Res2<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return ublox::message::CfgPrtUsbFieldsCommon::Reserved4Common::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        PortId,
        Reserved1,
        TxReady,
        Reserved2,
        InProtoMask,
        OutProtoMask,
        CfgPrtFlags,
        Reserved3,
        Reserved4
    >;
};

/// @brief Definition of <b>"CFG-PRT (USB)"</b> message class.
/// @details
///     See @ref CfgPrtUsbFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "ublox/message/CfgPrtUsb.h"
template <typename TMsgBase, typename TOpt = ublox::options::DefaultOptions>
class CfgPrtUsb : public
    comms::MessageBase<
        TMsgBase,
        comms::option::def::StaticNumIdImpl<ublox::MsgId_CfgPrt>,
        comms::option::def::FieldsImpl<typename CfgPrtUsbFields<TOpt>::All>,
        comms::option::def::MsgType<CfgPrtUsb<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            comms::option::def::StaticNumIdImpl<ublox::MsgId_CfgPrt>,
            comms::option::def::FieldsImpl<typename CfgPrtUsbFields<TOpt>::All>,
            comms::option::def::MsgType<CfgPrtUsb<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_portId type and @b field_portId() access fuction
    ///         for @ref CfgPrtUsbFields::PortId field.
    ///     @li @b Field_reserved1 type and @b field_reserved1() access fuction
    ///         for @ref CfgPrtUsbFields::Reserved1 field.
    ///     @li @b Field_txReady type and @b field_txReady() access fuction
    ///         for @ref CfgPrtUsbFields::TxReady field.
    ///     @li @b Field_reserved2 type and @b field_reserved2() access fuction
    ///         for @ref CfgPrtUsbFields::Reserved2 field.
    ///     @li @b Field_inProtoMask type and @b field_inProtoMask() access fuction
    ///         for @ref CfgPrtUsbFields::InProtoMask field.
    ///     @li @b Field_outProtoMask type and @b field_outProtoMask() access fuction
    ///         for @ref CfgPrtUsbFields::OutProtoMask field.
    ///     @li @b Field_cfgPrtFlags type and @b field_cfgPrtFlags() access fuction
    ///         for @ref CfgPrtUsbFields::CfgPrtFlags field.
    ///     @li @b Field_reserved3 type and @b field_reserved3() access fuction
    ///         for @ref CfgPrtUsbFields::Reserved3 field.
    ///     @li @b Field_reserved4 type and @b field_reserved4() access fuction
    ///         for @ref CfgPrtUsbFields::Reserved4 field.
    COMMS_MSG_FIELDS_NAMES(
        portId,
        reserved1,
        txReady,
        reserved2,
        inProtoMask,
        outProtoMask,
        cfgPrtFlags,
        reserved3,
        reserved4
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 22U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 22U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return ublox::message::CfgPrtUsbCommon::name();
    }
    
    
};

} // namespace message

} // namespace ublox

