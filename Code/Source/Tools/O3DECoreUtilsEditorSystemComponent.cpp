
#include <AzCore/Serialization/SerializeContext.h>
#include "O3DECoreUtilsEditorSystemComponent.h"

#include <O3DECoreUtils/O3DECoreUtilsTypeIds.h>

namespace O3DECoreUtils
{
    AZ_COMPONENT_IMPL(O3DECoreUtilsEditorSystemComponent, "O3DECoreUtilsEditorSystemComponent",
        O3DECoreUtilsEditorSystemComponentTypeId, BaseSystemComponent);

    void O3DECoreUtilsEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<O3DECoreUtilsEditorSystemComponent, O3DECoreUtilsSystemComponent>()
                ->Version(0);
        }
    }

    O3DECoreUtilsEditorSystemComponent::O3DECoreUtilsEditorSystemComponent() = default;

    O3DECoreUtilsEditorSystemComponent::~O3DECoreUtilsEditorSystemComponent() = default;

    void O3DECoreUtilsEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("O3DECoreUtilsEditorService"));
    }

    void O3DECoreUtilsEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("O3DECoreUtilsEditorService"));
    }

    void O3DECoreUtilsEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void O3DECoreUtilsEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void O3DECoreUtilsEditorSystemComponent::Activate()
    {
        O3DECoreUtilsSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void O3DECoreUtilsEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        O3DECoreUtilsSystemComponent::Deactivate();
    }

} // namespace O3DECoreUtils
