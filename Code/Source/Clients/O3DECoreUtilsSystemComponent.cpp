
#include "O3DECoreUtilsSystemComponent.h"

#include <O3DECoreUtils/O3DECoreUtilsTypeIds.h>

#include <AzCore/Serialization/SerializeContext.h>

namespace O3DECoreUtils
{
    AZ_COMPONENT_IMPL(O3DECoreUtilsSystemComponent, "O3DECoreUtilsSystemComponent",
        O3DECoreUtilsSystemComponentTypeId);

    void O3DECoreUtilsSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<O3DECoreUtilsSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void O3DECoreUtilsSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("O3DECoreUtilsService"));
    }

    void O3DECoreUtilsSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("O3DECoreUtilsService"));
    }

    void O3DECoreUtilsSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void O3DECoreUtilsSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    O3DECoreUtilsSystemComponent::O3DECoreUtilsSystemComponent()
    {
        if (O3DECoreUtilsInterface::Get() == nullptr)
        {
            O3DECoreUtilsInterface::Register(this);
        }
    }

    O3DECoreUtilsSystemComponent::~O3DECoreUtilsSystemComponent()
    {
        if (O3DECoreUtilsInterface::Get() == this)
        {
            O3DECoreUtilsInterface::Unregister(this);
        }
    }

    void O3DECoreUtilsSystemComponent::Init()
    {
    }

    void O3DECoreUtilsSystemComponent::Activate()
    {
        O3DECoreUtilsRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();
    }

    void O3DECoreUtilsSystemComponent::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        O3DECoreUtilsRequestBus::Handler::BusDisconnect();
    }

    void O3DECoreUtilsSystemComponent::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }

} // namespace O3DECoreUtils
