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
#define data_02111240 data_02110ee0
#define data_0211125c data_02110efc
#endif

extern ExtPaletteMappingData data_02111240;
extern TextureMappingData data_0211125c;
