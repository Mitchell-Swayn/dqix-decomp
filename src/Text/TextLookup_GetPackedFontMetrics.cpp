#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x20e7a94; symbol: data_020e7a94.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 020000000300000001010101010101010f00.
// Observed span: 18 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int TextLayoutDrawCachedGlyphRun_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x02042648; symbol: func_02042648; size: 0x10.
unsigned int TextLookup_GetPackedFontMetrics(int i){return TextLayoutDrawCachedGlyphRun_UnknownRoleInitializedBytes[i];}
}
