// Generated by commsdsl2comms v3.5.2

#include "RxmRlmLong.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/RxmRlmLong.h"
#include "cc_plugin/field/Res1.h"
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
    using Field = ublox::message::RxmRlmLongFields<>::Version;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_type()
{
    using Field = ublox::message::RxmRlmLongFields<>::Type;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .readOnly()
            .asMap();
    
}

static QVariantMap createProps_svid()
{
    using Field = ublox::message::RxmRlmLongFields<>::Svid;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved1()
{
    using Field = ublox::message::RxmRlmLongFields<>::Reserved1;
    auto props = cc_plugin::field::createProps_res1(Field::name());
    return props;
    
}

static QVariantMap createProps_beacon()
{
    using Field = ublox::message::RxmRlmLongFields<>::Beacon;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_message()
{
    using Field = ublox::message::RxmRlmLongFields<>::Message;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_params()
{
    using Field = ublox::message::RxmRlmLongFields<>::Params;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_reserved2()
{
    using Field = ublox::message::RxmRlmLongFields<>::Reserved2;
    auto props = cc_plugin::field::createProps_res3(Field::name());
    return props;
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_version());
    props.append(createProps_type());
    props.append(createProps_svid());
    props.append(createProps_reserved1());
    props.append(createProps_beacon());
    props.append(createProps_message());
    props.append(createProps_params());
    props.append(createProps_reserved2());
    return props;
}

} // namespace

class RxmRlmLongImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::RxmRlmLong<ublox::cc_plugin::Message>,
        RxmRlmLongImpl
    >
{
public:
    RxmRlmLongImpl() = default;
    RxmRlmLongImpl(const RxmRlmLongImpl&) = delete;
    RxmRlmLongImpl(RxmRlmLongImpl&&) = delete;
    virtual ~RxmRlmLongImpl() = default;
    RxmRlmLongImpl& operator=(const RxmRlmLongImpl&) = default;
    RxmRlmLongImpl& operator=(RxmRlmLongImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

RxmRlmLong::RxmRlmLong() : m_pImpl(new RxmRlmLongImpl) {}
RxmRlmLong::~RxmRlmLong() = default;

RxmRlmLong& RxmRlmLong::operator=(const RxmRlmLong& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

RxmRlmLong& RxmRlmLong::operator=(RxmRlmLong&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* RxmRlmLong::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& RxmRlmLong::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void RxmRlmLong::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void RxmRlmLong::resetImpl()
{
    m_pImpl->reset();
}

bool RxmRlmLong::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const RxmRlmLong*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

RxmRlmLong::MsgIdParamType RxmRlmLong::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus RxmRlmLong::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus RxmRlmLong::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool RxmRlmLong::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t RxmRlmLong::lengthImpl() const
{
    return m_pImpl->length();
}

bool RxmRlmLong::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

