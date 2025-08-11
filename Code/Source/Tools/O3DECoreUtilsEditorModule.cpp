
#include <O3DECoreUtils/O3DECoreUtilsTypeIds.h>
#include <O3DECoreUtilsModuleInterface.h>
#include "O3DECoreUtilsEditorSystemComponent.h"

namespace O3DECoreUtils
{
    class O3DECoreUtilsEditorModule
        : public O3DECoreUtilsModuleInterface
    {
    public:
        AZ_RTTI(O3DECoreUtilsEditorModule, O3DECoreUtilsEditorModuleTypeId, O3DECoreUtilsModuleInterface);
        AZ_CLASS_ALLOCATOR(O3DECoreUtilsEditorModule, AZ::SystemAllocator);

        O3DECoreUtilsEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                O3DECoreUtilsEditorSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<O3DECoreUtilsEditorSystemComponent>(),
            };
        }
    };
}// namespace O3DECoreUtils

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME, _Editor), O3DECoreUtils::O3DECoreUtilsEditorModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_O3DECoreUtils_Editor, O3DECoreUtils::O3DECoreUtilsEditorModule)
#endif
