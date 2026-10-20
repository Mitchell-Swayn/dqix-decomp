#include <globaldefs.h>

// Original data: arm9/main @ 0x2109da4; symbol: data_02109da4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" volatile unsigned char OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20f1962; symbol: data_020f1962.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000000000.
// Observed span: 7 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" volatile signed char OverlayLoaderPushPrimarySelection_UnknownRoleInitializedBytes[];
// Original data: arm9/main @ 0x2109dae; symbol: data_02109dae.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" volatile unsigned char OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" void DisableInterruptsAndHaltForever();
extern "C" void OverlayLoader_LoadOverlay(int);

// Original: arm9/main @ 0x020A1DF8; symbol: func_020a1df8; size: 0x5C.
extern "C" void OverlayLoader_PushPrimarySelection(unsigned int index) {
    if (OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage >= 8) {
        DisableInterruptsAndHaltForever();
    }
    if (index >= 7) {
        return;
    }
    OverlayLoader_LoadOverlay(OverlayLoaderPushPrimarySelection_UnknownRoleInitializedBytes[index]);
    OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage_Variant2[OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage] = (unsigned char)index;
    OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage = OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage + 1;
}
