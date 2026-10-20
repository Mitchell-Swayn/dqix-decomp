#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250c00; symbol: data_ov031_02250c00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* volatile WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage;
extern "C" void WfcNumberPad_SetKeyHighlight(int, int);
// Original: arm9/ov031 @ 0x022264C8; symbol: func_ov031_022264c8; size: 0x4C.
extern "C" void WfcNumberPad_SetHighlightedKey(int value) {
    if (value == *(signed char*)((char*)WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage + 0x62)) return;
    WfcNumberPad_SetKeyHighlight(value, 1);
    WfcNumberPad_SetKeyHighlight(*(signed char*)((char*)WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage + 0x62), 0);
    *((unsigned char*)WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage + 0x62) = (unsigned char)value;
}
