#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2107834; symbol: data_02107834.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char TextDrawClippedGlyphMask4Bpp_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x02042638; symbol: func_02042638; size: 0x10.
extern "C" unsigned int TextLookup_ReadIndexedGlobalWord(unsigned int i) { return ((unsigned int*)TextDrawClippedGlyphMask4Bpp_UnknownRoleZeroInitializedStorage)[i]; }
