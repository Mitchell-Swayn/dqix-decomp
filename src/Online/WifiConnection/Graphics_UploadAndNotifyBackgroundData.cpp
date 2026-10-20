#include <globaldefs.h>
ARM

extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void *, unsigned int);
extern "C" void LoadToSubBG1ScreenData(const void *, unsigned int, unsigned int);
extern "C" void WfcUtility_FreeArchiveResourceAndReturnPoolEntry(void *);
extern "C" void WfcUtility_RequestTaskRemoval(int, void *);
// Original data: arm9/ov031 @ 0x2290d04; symbol: data_ov031_02290d04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void * volatile AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage;

// Original: arm9/ov031 @ 0x022373FC; symbol: func_ov031_022373fc; size: 0x4C.
extern "C" void Graphics_UploadAndNotifyBackgroundData(void *value) {
    _Z25CleanInvalidateCacheRangePKvj(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage, 0x600);
    LoadToSubBG1ScreenData(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage, 0, 0x600);
    WfcUtility_FreeArchiveResourceAndReturnPoolEntry(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage);
    WfcUtility_RequestTaskRemoval(1, value);
}
