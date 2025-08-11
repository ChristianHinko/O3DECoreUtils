
#include "O3DECoreUtilsModuleInterface.h"
#include <AzCore/Memory/Memory.h>

#include <O3DECoreUtils/O3DECoreUtilsTypeIds.h>

#include <Clients/O3DECoreUtilsSystemComponent.h>

namespace O3DECoreUtils
{
    AZ_TYPE_INFO_WITH_NAME_IMPL(O3DECoreUtilsModuleInterface,
        "O3DECoreUtilsModuleInterface", O3DECoreUtilsModuleInterfaceTypeId);
    AZ_RTTI_NO_TYPE_INFO_IMPL(O3DECoreUtilsModuleInterface, AZ::Module);
    AZ_CLASS_ALLOCATOR_IMPL(O3DECoreUtilsModuleInterface, AZ::SystemAllocator);

    O3DECoreUtilsModuleInterface::O3DECoreUtilsModuleInterface()
    {
        // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
        // Add ALL components descriptors associated with this gem to m_descriptors.
        // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
        // This happens through the [MyComponent]::Reflect() function.
        m_descriptors.insert(m_descriptors.end(), {
            O3DECoreUtilsSystemComponent::CreateDescriptor(),
            });
    }

    AZ::ComponentTypeList O3DECoreUtilsModuleInterface::GetRequiredSystemComponents() const
    {
        return AZ::ComponentTypeList{
            azrtti_typeid<O3DECoreUtilsSystemComponent>(),
        };
    }
} // namespace O3DECoreUtils
