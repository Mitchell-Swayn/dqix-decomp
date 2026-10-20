#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cf4; symbol: data_ov031_02290cf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02235500; symbol: Network_SetInputModeAndRange; size: 0x2C.
// Stores the input mode at shared object+0x1c and stores 4 for mode 2, otherwise 6, at +0x1d.
extern "C" void Network_SetInputModeAndRange(unsigned char mode) {
    *((unsigned char *)*(void **)WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage + 0x1c) = mode;
    *((unsigned char *)*(void **)WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage + 0x1d) = mode == 2 ? 4 : 6;
}
