#include <globaldefs.h>
#include "System/LoadToVRAM.h"
extern "C" void RenderGlyphBitsIntoCharacterTiles(void*,int,int);
extern "C" void MIi_CpuClearFast(int,void*,unsigned);
// Original data: arm9/main @ 0x20ef788; symbol: data_020ef788.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 816900.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/main @ 0x20ef78b; symbol: data_020ef78b.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 824f00.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes_Variant3[];
// Original data: arm9/main @ 0x20ef78e; symbol: data_020ef78e.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 818100.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes_Variant4[];
// Original data: arm9/main @ 0x20ef791; symbol: data_020ef791.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 826000.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes_Variant5[];
// Original data: arm9/main @ 0x20ef794; symbol: data_020ef794.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 815e00.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes_Variant6[];
// Original data: arm9/main @ 0x20ef797; symbol: data_020ef797.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 814400.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes_Variant7[];
// Original data: arm9/main @ 0x20ef79a; symbol: data_020ef79a.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 817c00000000.
// Observed span: 6 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes_Variant8[];
// Original data: arm9/main @ 0x20e7170; symbol: data_020e7170.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ff7f000000000000000000000000000000000000000000000000000000000000ff7f007c007c007c000000000000000000000000000000000000000000000000 ...; full span in module reference.
// Observed span: 528 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes[];
// Original data: arm9/main @ 0x20fe9cc; symbol: data_020fe9cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1536 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char DebugTextWriteTileString_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0202AC74; symbol: func_0202ac74; size: 0xBC.
extern "C" ARM void Graphics_LoadBackgroundPaletteAndInitializeTileEntries()
{
    RenderGlyphBitsIntoCharacterTiles(GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes_Variant2,2,40);
    RenderGlyphBitsIntoCharacterTiles(GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes_Variant3,12,48);
    RenderGlyphBitsIntoCharacterTiles(GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes_Variant4,1,61);
    RenderGlyphBitsIntoCharacterTiles(GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes_Variant5,26,65);
    RenderGlyphBitsIntoCharacterTiles(GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes_Variant6,26,47);
    RenderGlyphBitsIntoCharacterTiles(GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes_Variant7,1,46);
    RenderGlyphBitsIntoCharacterTiles(GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes_Variant8,1,45);
    LoadToMainBGStandardPalette(GraphicsLoadBackgroundPaletteAndInitializeTileEntries_UnknownRoleInitializedBytes,0,512);
    MIi_CpuClearFast(0,DebugTextWriteTileString_UnknownRoleZeroInitializedStorage,1536);
}
