
#pragma once

namespace O3DECoreUtils
{
    // System Component TypeIds
    inline constexpr const char* O3DECoreUtilsSystemComponentTypeId = "{BB24F523-1FD0-4FA1-A862-3126458F2740}";
    inline constexpr const char* O3DECoreUtilsEditorSystemComponentTypeId = "{5B34CF7C-0D57-462D-A027-0E55ACB36302}";

    // Module derived classes TypeIds
    inline constexpr const char* O3DECoreUtilsModuleInterfaceTypeId = "{EEBFEC30-68DB-47FA-BE3C-7D477234A6DD}";
    inline constexpr const char* O3DECoreUtilsModuleTypeId = "{91EFF5D4-0317-4272-9D19-F78E2D5DC49D}";
    // The Editor Module by default is mutually exclusive with the Client Module
    // so they use the Same TypeId
    inline constexpr const char* O3DECoreUtilsEditorModuleTypeId = O3DECoreUtilsModuleTypeId;

    // Interface TypeIds
    inline constexpr const char* O3DECoreUtilsRequestsTypeId = "{5738B9F5-8ADC-40C6-9E6D-65748A109218}";
} // namespace O3DECoreUtils
