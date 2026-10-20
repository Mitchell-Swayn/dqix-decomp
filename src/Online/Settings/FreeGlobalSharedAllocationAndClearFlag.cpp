#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d34; symbol: data_ov031_02290d34.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *WfcUtilityIsScreenTransitionBusy_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
// Original: arm9/ov031 @ 0x0223C040; symbol: func_ov031_0223c040; size: 0x14.
extern "C" void FreeGlobalSharedAllocationAndClearFlag(void) {
    WfcUtility_FreeAllocationAndClearPointer(&WfcUtilityIsScreenTransitionBusy_UnknownRoleZeroInitializedStorage);
}
