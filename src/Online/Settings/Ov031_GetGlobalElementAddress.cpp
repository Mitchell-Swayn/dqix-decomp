#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d60; symbol: data_ov031_02290d60.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223DAA4; symbol: func_ov031_0223daa4; size: 0x18.
extern "C" void *Ov031_GetGlobalElementAddress(unsigned int row, unsigned int index) {
    return WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage + row * 0x400 + index * 8;
}
