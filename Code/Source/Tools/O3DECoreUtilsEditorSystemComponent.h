
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <Clients/O3DECoreUtilsSystemComponent.h>

namespace O3DECoreUtils
{
    /// System component for O3DECoreUtils editor
    class O3DECoreUtilsEditorSystemComponent
        : public O3DECoreUtilsSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = O3DECoreUtilsSystemComponent;
    public:
        AZ_COMPONENT_DECL(O3DECoreUtilsEditorSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        O3DECoreUtilsEditorSystemComponent();
        ~O3DECoreUtilsEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace O3DECoreUtils
