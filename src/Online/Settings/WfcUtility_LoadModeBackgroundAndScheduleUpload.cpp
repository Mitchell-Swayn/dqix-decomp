#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224bedc; symbol: data_ov031_0224bedc.
// Top-screen resource paths by utility screen.
// Initial values: hex 8cbe2402a0be2402b4be2402c8be240278be2402.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* WfcUtilityLoadModeBackgroundAndScheduleUpload_TopScreenResourcePathsByUtilityScreen[];
// Original data: arm9/ov031 @ 0x2290d04; symbol: data_ov031_02290d04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage;
extern "C" void* Graphics_UploadAndNotifyBackgroundData;
extern "C" void* WfcUtility_LocalizeResourcePath(void*);
extern "C" unsigned WfcUtility_LoadArchiveResource(void*, unsigned, unsigned);
extern "C" void WfcUtility_CreateTaskWithBorrowedContext(unsigned, void*, unsigned, unsigned);
// Original: arm9/ov031 @ 0x022373B4; symbol: func_ov031_022373b4; size: 0x48.
extern "C" void WfcUtility_LoadModeBackgroundAndScheduleUpload(unsigned index) {
    void* resource = WfcUtility_LocalizeResourcePath(WfcUtilityLoadModeBackgroundAndScheduleUpload_TopScreenResourcePathsByUtilityScreen[index]);
    unsigned handle = WfcUtility_LoadArchiveResource(resource, 0, 4);
    AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage = (void*)handle;
    WfcUtility_CreateTaskWithBorrowedContext(1, &Graphics_UploadAndNotifyBackgroundData, 0, 0x78);
}
