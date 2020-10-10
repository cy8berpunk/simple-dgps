// Generated by commsdsl2comms v3.5.2

#include "RxmPmreqV0.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/RxmPmreqV0.h"
#include "cc_plugin/field/Res3.h"

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_version()
{
    using Field = ublox::message::RxmPmreqV0Fields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::RxmPmreqV0Fields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res3(Field::name());
    return props;
    
}

static QVariantMap createProps_duration()
{
    using Field = ublox::message::RxmPmreqV0Fields<>::Duration;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_flags()
{
    using Field = ublox::message::RxmPmreqV0Fields<>::Flags;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(1U, "backup")
            .add(2U, "force")
            .asMap();
    
}

static QVariantMap createProps_wakeupSources()
{
    using Field = ublox::message::RxmPmreqV0Fields<>::WakeupSources;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(3U, "uartrx")
            .add(5U, "extint0")
            .add(6U, "extint1")
            .add(7U, "spics")
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_version());
    props.append(createProps_reserved1());
    props.append(createProps_duration());
    props.append(createProps_flags());
    props.append(createProps_wakeupSources());
    return props;
}

} // namespace

class RxmPmreqV0Impl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::RxmPmreqV0<ublox::cc_plugin::Message>,
        RxmPmreqV0Impl
    >
{
public:
    RxmPmreqV0Impl() = default;
    RxmPmreqV0Impl(const RxmPmreqV0Impl&) = delete;
    RxmPmreqV0Impl(RxmPmreqV0Impl&&) = delete;
    virtual ~RxmPmreqV0Impl() = default;
    RxmPmreqV0Impl& operator=(const RxmPmreqV0Impl&) = default;
    RxmPmreqV0Impl& operator=(RxmPmreqV0Impl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

RxmPmreqV0::RxmPmreqV0() : m_pImpl(new RxmPmreqV0Impl) {}
RxmPmreqV0::~RxmPmreqV0() = default;

RxmPmreqV0& RxmPmreqV0::operator=(const RxmPmreqV0& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

RxmPmreqV0& RxmPmreqV0::operator=(RxmPmreqV0&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* RxmPmreqV0::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& RxmPmreqV0::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void RxmPmreqV0::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void RxmPmreqV0::resetImpl()
{
    m_pImpl->reset();
}

bool RxmPmreqV0::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const RxmPmreqV0*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

RxmPmreqV0::MsgIdParamType RxmPmreqV0::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus RxmPmreqV0::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus RxmPmreqV0::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool RxmPmreqV0::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t RxmPmreqV0::lengthImpl() const
{
    return m_pImpl->length();
}

bool RxmPmreqV0::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

