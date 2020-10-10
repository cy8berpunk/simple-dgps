// Generated by commsdsl2comms v3.5.2

#include "AidAlpData.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "ublox/message/AidAlpData.h"
namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

struct AlpDataMembers
{
    static QVariantMap createProps_element()
    {
        using Field = ublox::message::AidAlpDataFields<>::AlpDataMembers::Element;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .asMap();
        
    }
    
};

static QVariantMap createProps_alpData()
{
    using Field = ublox::message::AidAlpDataFields<>::AlpData;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(AlpDataMembers::createProps_element())
            .serialisedHidden()
            .appendIndexToElementName()
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_alpData());
    return props;
}

} // namespace

class AidAlpDataImpl : public
    comms_champion::ProtocolMessageBase<
        ublox::message::AidAlpData<ublox::cc_plugin::Message>,
        AidAlpDataImpl
    >
{
public:
    AidAlpDataImpl() = default;
    AidAlpDataImpl(const AidAlpDataImpl&) = delete;
    AidAlpDataImpl(AidAlpDataImpl&&) = delete;
    virtual ~AidAlpDataImpl() = default;
    AidAlpDataImpl& operator=(const AidAlpDataImpl&) = default;
    AidAlpDataImpl& operator=(AidAlpDataImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

AidAlpData::AidAlpData() : m_pImpl(new AidAlpDataImpl) {}
AidAlpData::~AidAlpData() = default;

AidAlpData& AidAlpData::operator=(const AidAlpData& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

AidAlpData& AidAlpData::operator=(AidAlpData&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* AidAlpData::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& AidAlpData::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void AidAlpData::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void AidAlpData::resetImpl()
{
    m_pImpl->reset();
}

bool AidAlpData::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const AidAlpData*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

AidAlpData::MsgIdParamType AidAlpData::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus AidAlpData::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus AidAlpData::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool AidAlpData::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t AidAlpData::lengthImpl() const
{
    return m_pImpl->length();
}

bool AidAlpData::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace ublox

