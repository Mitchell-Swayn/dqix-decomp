#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e590; symbol: data_ov031_0224e590.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int *YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022113C0; symbol: func_ov031_022113c0; size: 0x50.
extern "C" int Ov031_IsGlobalModeTwoOrThree(void) {
    unsigned int *state = YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage;
    if (state == 0) return 0;
    switch (*state) {
    case 0:
    case 1:
        return 0;
    case 2:
    case 3:
        return 1;
    default:
        return 0;
    }
}
