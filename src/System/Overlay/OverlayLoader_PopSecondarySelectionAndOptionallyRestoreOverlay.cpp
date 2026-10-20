#include <globaldefs.h>
#pragma optimize_for_size off
// Original data: arm9/main @ 0x2109da4; symbol: data_02109da4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" volatile unsigned char OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2109da6; symbol: data_02109da6.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" volatile unsigned char OverlayLoaderSetSecondarySelection_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x20f1977; symbol: data_020f1977.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000000000.
// Observed span: 7 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" signed char OverlayLoaderPushSecondarySelection_UnknownRoleInitializedBytes[];
extern "C" void OverlayLoader_LoadOverlay(int);
// Original: arm9/main @ 0x020A1F4C; symbol: func_020a1f4c; size: 0x5C.
extern "C" void OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(int enabled) {
    if (OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[1] == 0) return;
    OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[1] = OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[1] - 1;
    if (enabled != 0) {
        int count = OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[1];
        if (count != 0) {
            int index = (int)(signed char)OverlayLoaderSetSecondarySelection_UnknownRoleZeroInitializedStorage[OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[1] - 1];
            OverlayLoader_LoadOverlay((int)OverlayLoaderPushSecondarySelection_UnknownRoleInitializedBytes[index]);
        }
    }
}
