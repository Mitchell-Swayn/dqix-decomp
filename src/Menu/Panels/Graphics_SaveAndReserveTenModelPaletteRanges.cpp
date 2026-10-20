#include <globaldefs.h>
ARM
// Original data: arm9/ov023 @ 0x21fd6ac; symbol: data_ov023_021fd6ac.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00440000001000000010000000000000001000000008000000080000000800000008000000080000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" unsigned int GraphicsSaveAndReserveTenModelPaletteRanges_UnknownRoleInitializedBytes[];
// Original data: arm9/ov023 @ 0x21fd6fc; symbol: data_ov023_021fd6fc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 200200004000000040000000000000004000000040000000400000004000000040000000400000001000000008000000.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" unsigned int GraphicsSaveAndReserveTenModelPaletteRanges_UnknownRoleInitializedBytes_Variant2[];
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(void *, unsigned int, unsigned int);
// Original: arm9/ov023 @ 0x021E4FD8; symbol: func_ov023_021e4fd8; size: 0x48.
extern "C" void Graphics_SaveAndReserveTenModelPaletteRanges(void *p) {
    for (int i = 0; i < 10; ++i)
        VRAM_SaveStateAndReserveImagePaletteBytes((char *)p + 0x794 + i * 0x70,
            GraphicsSaveAndReserveTenModelPaletteRanges_UnknownRoleInitializedBytes[i], GraphicsSaveAndReserveTenModelPaletteRanges_UnknownRoleInitializedBytes_Variant2[i]);
}
