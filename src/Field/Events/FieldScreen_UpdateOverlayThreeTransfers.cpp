#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d8478; symbol: data_ov017_021d8478.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned char FieldScreenUpdateOverlayThreeSession_UnknownRoleZeroInitializedStorage[];
extern "C" void Alltrades_DrawVocationMenu(void *);
// Original: arm9/ov017 @ 0x021C162C; symbol: func_ov017_021c162c; size: 0x20.
extern "C" void FieldScreen_UpdateOverlayThreeTransfers(void) {
    void *object = *(void **)FieldScreenUpdateOverlayThreeSession_UnknownRoleZeroInitializedStorage;
    if (object != 0)
        Alltrades_DrawVocationMenu(object);
}
