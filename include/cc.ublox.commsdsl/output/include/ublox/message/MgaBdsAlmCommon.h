// Generated by commsdsl2comms v3.5.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref ublox::message::MgaBdsAlm message and its fields.

#pragma once

#include <cstdint>
#include "ublox/field/Res1Common.h"
#include "ublox/field/Res4Common.h"

namespace ublox
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref ublox::message::MgaBdsAlm message.
/// @see ublox::message::MgaBdsAlmFields
struct MgaBdsAlmFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::Type field.
    struct TypeCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MgaBdsAlmFields::Type field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::Type field.
        static const char* name()
        {
            return "type";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::Version field.
    struct VersionCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MgaBdsAlmFields::Version field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::Version field.
        static const char* name()
        {
            return "version";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::Svid field.
    struct SvidCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MgaBdsAlmFields::Svid field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::Svid field.
        static const char* name()
        {
            return "svid";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::Reserved1 field.
    struct Reserved1Common : public ublox::field::Res1Common
    {
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::Reserved1 field.
        static const char* name()
        {
            return "reserved1";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::Wna field.
    struct WnaCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MgaBdsAlmFields::Wna field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::Wna field.
        static const char* name()
        {
            return "Wna";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::Toa field.
    struct ToaCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MgaBdsAlmFields::Toa field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::Toa field.
        static const char* name()
        {
            return "toa";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::DeltaI field.
    struct DeltaICommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MgaBdsAlmFields::DeltaI field.
        using ValueType = std::int16_t;
    
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::DeltaI field.
        static const char* name()
        {
            return "deltaI";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::SqrtA field.
    struct SqrtACommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MgaBdsAlmFields::SqrtA field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::SqrtA field.
        static const char* name()
        {
            return "sqrtA";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::E field.
    struct ECommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MgaBdsAlmFields::E field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::E field.
        static const char* name()
        {
            return "e";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::Omega field.
    struct OmegaCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MgaBdsAlmFields::Omega field.
        using ValueType = std::int32_t;
    
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::Omega field.
        static const char* name()
        {
            return "omega";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::M0 field.
    struct M0Common
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MgaBdsAlmFields::M0 field.
        using ValueType = std::int32_t;
    
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::M0 field.
        static const char* name()
        {
            return "M0";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::Omega0 field.
    struct Omega0Common
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MgaBdsAlmFields::Omega0 field.
        using ValueType = std::int32_t;
    
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::Omega0 field.
        static const char* name()
        {
            return "Omega0";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::OmegaDot field.
    struct OmegaDotCommon
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MgaBdsAlmFields::OmegaDot field.
        using ValueType = std::int32_t;
    
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::OmegaDot field.
        static const char* name()
        {
            return "omegaDot";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::A0 field.
    struct A0Common
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MgaBdsAlmFields::A0 field.
        using ValueType = std::int16_t;
    
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::A0 field.
        static const char* name()
        {
            return "a0";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::A1 field.
    struct A1Common
    {
        /// @brief Re-definition of the value type used by
        ///     ublox::message::MgaBdsAlmFields::A1 field.
        using ValueType = std::int16_t;
    
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::A1 field.
        static const char* name()
        {
            return "a1";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref ublox::message::MgaBdsAlmFields::Reserved2 field.
    struct Reserved2Common : public ublox::field::Res4Common
    {
        /// @brief Name of the @ref ublox::message::MgaBdsAlmFields::Reserved2 field.
        static const char* name()
        {
            return "reserved2";
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref ublox::message::MgaBdsAlm message.
/// @see ublox::message::MgaBdsAlm
struct MgaBdsAlmCommon
{
    /// @brief Name of the @ref ublox::message::MgaBdsAlm message.
    static const char* name()
    {
        return "MGA-BDS-ALM";
    }
    
};

} // namespace message

} // namespace ublox

