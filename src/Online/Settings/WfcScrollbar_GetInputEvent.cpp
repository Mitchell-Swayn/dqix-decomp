#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cf4; symbol: data_ov031_02290cf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022351E4; symbol: func_ov031_022351e4; size: 0x14.
extern "C" unsigned int WfcScrollbar_GetInputEvent(void) {
    unsigned char *object = *(unsigned char **)&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage;
    return object[0x1d];
}
