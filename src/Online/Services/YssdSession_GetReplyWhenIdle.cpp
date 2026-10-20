#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e590; symbol: data_ov031_0224e590.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x022112E4; symbol: func_ov031_022112e4; size: 0x2C.
extern "C" void *YssdSession_GetReplyWhenIdle(void) {
    unsigned char *object = *(unsigned char **)YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage;
    return object != 0 && *(unsigned int *)(object + 0x30) == 0
        ? *(void **)(object + 0x2c)
        : 0;
}
