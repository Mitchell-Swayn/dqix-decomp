#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c40; symbol: data_ov031_02290c40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *WfcUtilityLoadMessageTable_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **p);
// Original: arm9/ov031 @ 0x0222761C; symbol: func_ov031_0222761c; size: 0x14.
extern "C" void WfcUtility_FreeMessageTablePool(void) {
    WfcUtility_FreeAllocationAndClearPointer((void **)&WfcUtilityLoadMessageTable_UnknownRoleZeroInitializedStorage);
}
