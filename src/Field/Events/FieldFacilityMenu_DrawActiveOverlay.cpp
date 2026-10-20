#include <globaldefs.h>
ARM
extern "C" void Graphics_RefreshActivePageTransfersAndParts(void);
// Original data: arm9/ov017 @ 0x21d840c; symbol: data_ov017_021d840c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned int OverlayPopAndDestroyObject_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov017 @ 0x021B2F0C; symbol: func_ov017_021b2f0c; size: 0x20.
extern "C" void FieldFacilityMenu_DrawActiveOverlay(void) {
    if (OverlayPopAndDestroyObject_UnknownRoleZeroInitializedStorage == 0)
        return;
    Graphics_RefreshActivePageTransfersAndParts();
}
