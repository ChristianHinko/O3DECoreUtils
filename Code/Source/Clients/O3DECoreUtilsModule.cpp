
#include <O3DECoreUtils/O3DECoreUtilsTypeIds.h>
#include <O3DECoreUtilsModuleInterface.h>
#include "O3DECoreUtilsSystemComponent.h"

namespace O3DECoreUtils
{
    class O3DECoreUtilsModule
        : public O3DECoreUtilsModuleInterface
    {
    public:
        AZ_RTTI(O3DECoreUtilsModule, O3DECoreUtilsModuleTypeId, O3DECoreUtilsModuleInterface);
        AZ_CLASS_ALLOCATOR(O3DECoreUtilsModule, AZ::SystemAllocator);
    };
}// namespace O3DECoreUtils

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), O3DECoreUtils::O3DECoreUtilsModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_O3DECoreUtils, O3DECoreUtils::O3DECoreUtilsModule)
#endif
