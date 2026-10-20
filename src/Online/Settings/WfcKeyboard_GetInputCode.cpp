#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250bfc; symbol: data_ov031_02250bfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02223FA0; symbol: func_ov031_02223fa0; size: 0x14.
extern "C" unsigned int WfcKeyboard_GetInputCode(void) {
    unsigned char *p = *(unsigned char **)&WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage;
    return p[0x11c];
}
