#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e590; symbol: data_ov031_0224e590.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" volatile unsigned YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage;
extern "C" int Ov031_IsGlobalModeTwoOrThree();
extern "C" void YssdClient_SetError(int, int);
// Original: arm9/ov031 @ 0x022110F0; symbol: func_ov031_022110f0; size: 0x48.
extern "C" void Overlay_SetGlobalValueOrFallback(int value) {
    if (!*(void**)&YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage) goto fallback;
    if (Ov031_IsGlobalModeTwoOrThree()) goto fallback;
    goto success;
fallback:
    YssdClient_SetError(9, -2);
    return;
success:
    *(int*)((char*)*(void**)&YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage + 0x3c) = value;
}
