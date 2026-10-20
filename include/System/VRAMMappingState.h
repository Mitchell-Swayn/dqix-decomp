#pragma once

// Temporary mappings held while extended palettes and texture data are loaded.
// These records preserve the layouts used by the release/map/unmap operations.
struct ExtPaletteMappingData
{
    // Sub BG uses bank H, so its map address is fixed.
    int subBGExtPaletteBanks_240_;
    // Main OBJ uses F or G; either bank is twice the palette allocation size.
    unsigned int mainObjExtPaletteMapAddress_244_;
    int mainObjExtPaletteBanks_248_;
    // Main BG uses E/F/G. Bank G alone represents the second 16 KiB block.
    unsigned int mainBGExtPaletteInitialOffset_24c_;
    unsigned int mainBGExtPaletteMapAddress_250_;
    int mainBGExtPaletteBanks_254_;
    // Sub OBJ uses bank I, so its map address is fixed.
    int subObjExtPaletteBanks_258_;
};

struct TextureMappingData
{
    int clearTextureBanks_25c_;
    // Texture image banks A-D can span two separate memory blocks.
    unsigned int textureImageFirstMapAddress_260_;
    unsigned int texturePaletteMapAddress_264_;
    int texturePaletteBanks_268_;
    unsigned int clearTextureMapAddress_26c_;
    int textureImageBanks_270_;
    unsigned int textureImageSecondMapAddress_274_;
    unsigned int textureImageFirstMapRegionSize_278_;
};

#if defined(jpn)
#define LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage data_02110ee0
#define LoadClearImage_UnknownRoleZeroInitializedStorage data_02110efc
#endif

// Original data: arm9/main @ 0x2111240; symbol: data_02111240.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern ExtPaletteMappingData LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x211125c; symbol: data_0211125c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern TextureMappingData LoadClearImage_UnknownRoleZeroInitializedStorage;
