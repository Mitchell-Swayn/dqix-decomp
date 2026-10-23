#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250bf4; symbol: data_ov031_02250bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *LoadAndSelectMainBG1Data_UnknownRoleZeroInitializedStorage;
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void *, unsigned);
extern "C" void LoadToMainBG1ScreenData(const void *, unsigned, unsigned);
extern "C" void WfcUtility_RequestTaskRemoval(unsigned,void*);
// Original: arm9/ov031 @ 0x02223A24; symbol: func_ov031_02223a24; size: 0x40.
extern "C" void LoadAndSelectMainBG1Data(void* argument,void*) {
    _Z25CleanInvalidateCacheRangePKvj(LoadAndSelectMainBG1Data_UnknownRoleZeroInitializedStorage, 0xc0);
    LoadToMainBG1ScreenData(LoadAndSelectMainBG1Data_UnknownRoleZeroInitializedStorage, 0, 0xc0);
    WfcUtility_RequestTaskRemoval(1, argument);
}
