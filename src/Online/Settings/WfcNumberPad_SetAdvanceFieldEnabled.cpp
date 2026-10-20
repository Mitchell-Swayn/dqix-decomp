#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250c00; symbol: data_ov031_02250c00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char *WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02225C60; symbol: func_ov031_02225c60; size: 0x14.
extern "C" void WfcNumberPad_SetAdvanceFieldEnabled(int a0) {
    *(unsigned char *)(WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage + 0x68) = a0;
}
