#include <globaldefs.h>
ARM
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void *, unsigned int);
extern "C" void LoadToMainOAM(const void *, unsigned int, unsigned int);
extern "C" void LoadToSubOAM(const void *, unsigned int, unsigned int);
// Original data: arm9/ov031 @ 0x2290d60; symbol: data_ov031_02290d60.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char * volatile WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage;

// Original: arm9/ov031 @ 0x0223D9C4; symbol: func_ov031_0223d9c4; size: 0x48.
extern "C" void Graphics_FlushAndLoadOAM(void*,void*) {
    _Z25CleanInvalidateCacheRangePKvj(WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage, 0x800);
    LoadToMainOAM(WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage, 0, 0x400);
    LoadToSubOAM(WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage + 0x400, 0, 0x400);
}
