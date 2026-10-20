#include <globaldefs.h>
#pragma optimize_for_size off
// Original data: arm9/main @ 0x2109da4; symbol: data_02109da4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" volatile unsigned char OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2109dae; symbol: data_02109dae.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" volatile signed char OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/main @ 0x20f1962; symbol: data_020f1962.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000000000.
// Observed span: 7 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" signed char OverlayLoaderPushPrimarySelection_UnknownRoleInitializedBytes[];
extern "C" void OverlayLoader_LoadOverlay(int);
// Original: arm9/main @ 0x020A1E54; symbol: func_020a1e54; size: 0x5C.
extern "C" void OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(int enabled) {
    if (OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[0] == 0) return;
    OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[0] = OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[0] - 1;
    if (enabled != 0) {
        int count = OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[0];
        if (count != 0) {
            int index = (int)(signed char)OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage_Variant2[OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[0] - 1];
            OverlayLoader_LoadOverlay((int)OverlayLoaderPushPrimarySelection_UnknownRoleInitializedBytes[index]);
        }
    }
}
