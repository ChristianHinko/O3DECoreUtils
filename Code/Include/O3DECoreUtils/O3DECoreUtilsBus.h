
#pragma once

#include <O3DECoreUtils/O3DECoreUtilsTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace O3DECoreUtils
{
    class O3DECoreUtilsRequests
    {
    public:
        AZ_RTTI(O3DECoreUtilsRequests, O3DECoreUtilsRequestsTypeId);
        virtual ~O3DECoreUtilsRequests() = default;
        // Put your public methods here
    };

    class O3DECoreUtilsBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using O3DECoreUtilsRequestBus = AZ::EBus<O3DECoreUtilsRequests, O3DECoreUtilsBusTraits>;
    using O3DECoreUtilsInterface = AZ::Interface<O3DECoreUtilsRequests>;

} // namespace O3DECoreUtils
