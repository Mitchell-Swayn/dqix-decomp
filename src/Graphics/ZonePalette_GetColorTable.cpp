#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2109dcc; symbol: data_02109dcc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 512 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char ZonePaletteGetColorTable_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020A6084; symbol: func_020a6084; size: 0xC.
extern "C" void* ZonePalette_GetColorTable() { return ZonePaletteGetColorTable_UnknownRoleZeroInitializedStorage; }
