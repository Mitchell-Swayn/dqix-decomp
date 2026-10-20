#include "System/LoadToVRAM.h"
#include "System/DMA.h"
#include "System/BGBases.h"
#include "System/VRAM.h"
#include "System/VRAMMappingState.h"
#include <globaldefs.h>
#include <asmhacks.h>

#pragma optimize_for_size off

#if defined(jpn)
#define MIi_CpuCopy16 func_020cbe84
#define MIi_CpuCopy32 func_020cbed4

#define MemoryMapTexturePalette_UnknownRoleInitializedBytes data_020ed764
#define MemoryMapTextureImage_UnknownRoleInitializedBytes data_020ed774
#endif

#define ADDR_MAIN_BG_STANDARD_PALETTE 0x05000000
#define ADDR_MAIN_OBJ_STANDARD_PALETTE 0x05000200
#define ADDR_SUB_BG_STANDARD_PALETTE 0x05000400
#define ADDR_SUB_OBJ_STANDARD_PALETTE 0x05000600

// Address lookup table for texture palette memory mapping using
// banks E, F, G. The bitmasks for these are 0, 0x10, 0x20, ..., 0x70
// so index into the table with (banks >> 4)
// Original data: arm9/main @ 0x20ed658; symbol: data_020ed658.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00008068906880689468000090688068.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const unsigned short MemoryMapTexturePalette_UnknownRoleInitializedBytes[8];

// Holds triples (first block start, second block start, first block size)
// for texture image memory mapping using banks A-D.
// All quantities are right shifted by 12 so that they fit into u16s
// Original data: arm9/main @ 0x20ed668; symbol: data_020ed668.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const unsigned short MemoryMapTextureImage_UnknownRoleInitializedBytes[48];

extern "C"
{
    // inverted memcpy via u16s
    void MIi_CpuCopy16(const void* src, void* dst, unsigned len);
    // inverted memcpy via u32s
    void MIi_CpuCopy32(const void* src, void* dst, unsigned len);
}

// Original: arm9/main @ 0x020C5820; symbol: LoadToMainBGStandardPalette; size: 0x54.
void LoadToMainBGStandardPalette(const void* data, unsigned int offset, unsigned int length)
{
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 28)
        DMAMemcpySynchronous16Bit(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, 0x05000000 + offset, length);
    else
        MIi_CpuCopy16(data, (void*)(0x05000000 + offset), length);
}

// Original: arm9/main @ 0x020C5874; symbol: LoadToSubBGStandardPalette; size: 0x58.
void LoadToSubBGStandardPalette(const void* data, unsigned int offset, unsigned int length)
{
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 28)
        DMAMemcpySynchronous16Bit(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, 0x05000400 + offset, length);
    else
        MIi_CpuCopy16(data, (void*)(0x05000400 + offset), length);
}

// Original: arm9/main @ 0x020C58CC; symbol: LoadToMainObjStandardPalette; size: 0x58.
void LoadToMainObjStandardPalette(const void* data, unsigned int offset, unsigned int length)
{
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 28)
        DMAMemcpySynchronous16Bit(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, 0x05000200 + offset, length);
    else
        MIi_CpuCopy16(data, (void*)(0x05000200 + offset), length);
}

// Original: arm9/main @ 0x020C5924; symbol: LoadToSubObjStandardPalette; size: 0x58.
void LoadToSubObjStandardPalette(const void* data, unsigned int offset, unsigned int length)
{
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 28)
        DMAMemcpySynchronous16Bit(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, 0x05000600 + offset, length);
    else
        MIi_CpuCopy16(data, (void*)(0x05000600 + offset), length);
}

// Original: arm9/main @ 0x020C597C; symbol: LoadToMainOAM; size: 0x54.
void LoadToMainOAM(const void* data, unsigned int offset, unsigned int length)
{
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 48)
        DMAMemcpySynchronous(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, 0x07000000 + offset, length);
    else
        MIi_CpuCopy32(data, (void*)(0x07000000 + offset), length);
}

// Original: arm9/main @ 0x020C59D0; symbol: LoadToSubOAM; size: 0x58.
void LoadToSubOAM(const void* data, unsigned int offset, unsigned int length)
{
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 48)
        DMAMemcpySynchronous(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, 0x07000400 + offset, length);
    else
        MIi_CpuCopy32(data, (void*)(0x07000400 + offset), length);
}

// not quite a match
// Original: arm9/main @ 0x020C5A28; symbol: LoadToMainObjVRAM; size: 0x58.
void LoadToMainObjVRAM(const void* data, unsigned int offset, unsigned int length)
{
    int writeAddr = 0x06400000;
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 48)
    {
        writeAddr += offset;
        DMAMemcpySynchronous(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, writeAddr, length);
    }
    else
    {
        writeAddr += offset;
        MIi_CpuCopy32(data, (void*)writeAddr, length);
    }
}

// not quite a match
// Original: arm9/main @ 0x020C5A80; symbol: LoadToSubObjVRAM; size: 0x58.
void LoadToSubObjVRAM(const void* data, unsigned int offset, unsigned int length)
{
    int writeAddr = 0x06600000;
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 48)
    {
        writeAddr += offset;
        DMAMemcpySynchronous(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, writeAddr, length);
    }
    else
    {
        writeAddr += offset;
        MIi_CpuCopy32(data, (void*)writeAddr, length);
    }
}

// Original: arm9/main @ 0x020C5AD8; symbol: LoadToMainBG0ScreenData; size: 0x60.
void LoadToMainBG0ScreenData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetMainBG0ScreenBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 28)
        DMAMemcpySynchronous16Bit(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy16(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C5B38; symbol: LoadToSubBG0ScreenData; size: 0x60.
void LoadToSubBG0ScreenData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetSubBG0ScreenBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 28)
        DMAMemcpySynchronous16Bit(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy16(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C5B98; symbol: LoadToMainBG1ScreenData; size: 0x60.
void LoadToMainBG1ScreenData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetMainBG1ScreenBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 28)
        DMAMemcpySynchronous16Bit(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy16(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C5BF8; symbol: LoadToSubBG1ScreenData; size: 0x60.
void LoadToSubBG1ScreenData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetSubBG1ScreenBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 28)
        DMAMemcpySynchronous16Bit(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy16(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C5C58; symbol: LoadToMainBG2ScreenData; size: 0x60.
void LoadToMainBG2ScreenData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetMainBG2ScreenBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 28)
        DMAMemcpySynchronous16Bit(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy16(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C5CB8; symbol: LoadToSubBG2ScreenData; size: 0x60.
void LoadToSubBG2ScreenData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetSubBG2ScreenBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 28)
        DMAMemcpySynchronous16Bit(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy16(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C5D18; symbol: LoadToMainBG3ScreenData; size: 0x60.
void LoadToMainBG3ScreenData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetMainBG3ScreenBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 28)
        DMAMemcpySynchronous16Bit(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy16(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C5D78; symbol: LoadToSubBG3ScreenData; size: 0x60.
void LoadToSubBG3ScreenData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetSubBG3ScreenBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 28)
        DMAMemcpySynchronous16Bit(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy16(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C5DD8; symbol: LoadToMainBG0CharacterData; size: 0x60.
void LoadToMainBG0CharacterData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetMainBG0CharacterBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 48)
        DMAMemcpySynchronous(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy32(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C5E38; symbol: LoadToSubBG0CharacterData; size: 0x60.
void LoadToSubBG0CharacterData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetSubBG0CharacterBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 48)
        DMAMemcpySynchronous(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy32(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C5E98; symbol: LoadToMainBG1CharacterData; size: 0x60.
void LoadToMainBG1CharacterData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetMainBG1CharacterBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 48)
        DMAMemcpySynchronous(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy32(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C5EF8; symbol: LoadToSubBG1CharacterData; size: 0x60.
void LoadToSubBG1CharacterData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetSubBG1CharacterBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 48)
        DMAMemcpySynchronous(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy32(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C5F58; symbol: LoadToMainBG2CharacterData; size: 0x60.
void LoadToMainBG2CharacterData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetMainBG2CharacterBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 48)
        DMAMemcpySynchronous(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy32(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C5FB8; symbol: LoadToSubBG2CharacterData; size: 0x60.
void LoadToSubBG2CharacterData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetSubBG2CharacterBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 48)
        DMAMemcpySynchronous(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy32(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C6018; symbol: LoadToMainBG3CharacterData; size: 0x60.
void LoadToMainBG3CharacterData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetMainBG3CharacterBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 48)
        DMAMemcpySynchronous(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy32(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C6078; symbol: LoadToSubBG3CharacterData; size: 0x60.
void LoadToSubBG3CharacterData(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int base = GetSubBG3CharacterBase();
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && length > 48)
        DMAMemcpySynchronous(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, base + offset, length);
    else
        MIi_CpuCopy32(data, (void*)(base + offset), length);
}

// Original: arm9/main @ 0x020C60D8; symbol: MemoryMapMainBGExtendedPalette; size: 0xA0.
void MemoryMapMainBGExtendedPalette()
{
    LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainBGExtPaletteBanks_254_ = ReleaseMainBGExtendedPaletteVRAMBanks();
    switch (LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainBGExtPaletteBanks_254_)
    {
    case VRAM_BANK_E:
        LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainBGExtPaletteMapAddress_250_ = 0x06880000;
        LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainBGExtPaletteInitialOffset_24c_ = 0;
        break;
    case VRAM_BANK_G:
        LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainBGExtPaletteMapAddress_250_ = 0x06894000;
        LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainBGExtPaletteInitialOffset_24c_ = 16 * 1024;
        break;
    case VRAM_BANK_F | VRAM_BANK_G:
    case VRAM_BANK_F:
        LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainBGExtPaletteMapAddress_250_ = 0x06890000;
        LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainBGExtPaletteInitialOffset_24c_ = 0;
        break;
    case 0:
        break;
    }
}

// Original: arm9/main @ 0x020C6178; symbol: LoadToMainBGExtendedPalette; size: 0x70.
void LoadToMainBGExtendedPalette(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int dest = LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainBGExtPaletteMapAddress_250_ + offset - LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainBGExtPaletteInitialOffset_24c_;
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1)
        DMAMemcpyAsync(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, dest, length, NULL, 0);
    else
        MIi_CpuCopy32(data, (void*)dest, length);
}

// Original: arm9/main @ 0x020C61E8; symbol: MemoryUnmapMainBGExtendedPalette; size: 0x48.
void MemoryUnmapMainBGExtendedPalette()
{
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1)
        AwaitDMACompletion(LoadToSubOAM_UnknownRoleInitializedBytes);

    MapVRAMBanksToMainBGExtendedPalette(LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainBGExtPaletteBanks_254_);
    LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainBGExtPaletteBanks_254_ = 0;
    LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainBGExtPaletteMapAddress_250_ = 0;
    LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainBGExtPaletteInitialOffset_24c_ = 0;
}

// Original: arm9/main @ 0x020C6230; symbol: MemoryMapMainObjExtendedPalette; size: 0x48.
void MemoryMapMainObjExtendedPalette()
{
    LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainObjExtPaletteBanks_248_ = ReleaseMainObjExtendedPaletteVRAMBanks();
    switch (LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainObjExtPaletteBanks_248_)
    {
    case 0:
        break;
    case VRAM_BANK_F:
        LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainObjExtPaletteMapAddress_244_ = 0x06890000;
        break;
    case VRAM_BANK_G:
        LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainObjExtPaletteMapAddress_244_ = 0x06894000;
        break;
    }
}

// Original: arm9/main @ 0x020C6278; symbol: LoadToMainObjExtendedPalette; size: 0x6C.
void LoadToMainObjExtendedPalette(const void* data, unsigned int offset, unsigned int length)
{
    int dmaChannel = LoadToSubOAM_UnknownRoleInitializedBytes;
    unsigned int dest = LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainObjExtPaletteMapAddress_244_ + offset;
    if (dmaChannel != -1)
        DMAMemcpyAsync(dmaChannel, (unsigned int)data, dest, length, NULL, 0);
    else
        MIi_CpuCopy32(data, (void*)dest, length);
}

// Original: arm9/main @ 0x020C62E4; symbol: MemoryUnmapMainObjExtendedPalette; size: 0x44.
void MemoryUnmapMainObjExtendedPalette()
{
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1)
        AwaitDMACompletion(LoadToSubOAM_UnknownRoleInitializedBytes);

    MapVRAMBanksToMainObjExtendedPalette(LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainObjExtPaletteBanks_248_);
    LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainObjExtPaletteBanks_248_ = 0;
    LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.mainObjExtPaletteMapAddress_244_ = 0;
}

// Original: arm9/main @ 0x020C6328; symbol: MemoryMapSubBGExtendedPalette; size: 0x18.
void MemoryMapSubBGExtendedPalette()
{
    LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.subBGExtPaletteBanks_240_ = ReleaseSubBGExtendedPaletteVRAMBanks();
}

// Original: arm9/main @ 0x020C6340; symbol: LoadToSubBGExtendedPalette; size: 0x64.
void LoadToSubBGExtendedPalette(const void* data, unsigned int offset, unsigned int length)
{
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1)
        DMAMemcpyAsync(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, 0x06898000 + offset, length, NULL, 0);
    else
        MIi_CpuCopy32(data, (void*)(0x06898000 + offset), length);
}

// Original: arm9/main @ 0x020C63A4; symbol: MemoryUnmapSubBGExtendedPalette; size: 0x40.
void MemoryUnmapSubBGExtendedPalette()
{
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1)
        AwaitDMACompletion(LoadToSubOAM_UnknownRoleInitializedBytes);
    
    MapVRAMBanksToSubBGExtendedPalette(LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.subBGExtPaletteBanks_240_);
    LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.subBGExtPaletteBanks_240_ = 0;
}

// Original: arm9/main @ 0x020C63E4; symbol: MemoryMapSubObjExtendedPalette; size: 0x18.
void MemoryMapSubObjExtendedPalette()
{
    LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.subObjExtPaletteBanks_258_ = ReleaseSubObjExtendedPaletteVRAMBanks();
}

// Original: arm9/main @ 0x020C63FC; symbol: LoadToSubObjExtendedPalette; size: 0x64.
void LoadToSubObjExtendedPalette(const void* data, unsigned int offset, unsigned int length)
{
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1)
        DMAMemcpyAsync(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, 0x068a0000 + offset, length, NULL, 0);
    else
        MIi_CpuCopy32(data, (void*)(0x068a0000 + offset), length);
}

// Original: arm9/main @ 0x020C6460; symbol: MemoryUnmapSubObjExtendedPalette; size: 0x40.
void MemoryUnmapSubObjExtendedPalette()
{
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1)
        AwaitDMACompletion(LoadToSubOAM_UnknownRoleInitializedBytes);

    MapVRAMBanksToSubObjExtendedPalette(LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.subObjExtPaletteBanks_258_);
    LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage.subObjExtPaletteBanks_258_ = 0;
}

// Original: arm9/main @ 0x020C64A0; symbol: MemoryMapTextureImage; size: 0x5C.
void MemoryMapTextureImage()
{
    int banks = ReleaseTextureImageVRAMBanks();
    LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageBanks_270_ = banks;

    struct LookupEntry {
        unsigned short entry;
        unsigned short pad[2];
    };

    const LookupEntry* firstBlockLookup =  (const LookupEntry*)&MemoryMapTextureImage_UnknownRoleInitializedBytes[0];
    const LookupEntry* secondBlockLookup = (const LookupEntry*)&MemoryMapTextureImage_UnknownRoleInitializedBytes[1];
    const LookupEntry* thirdBlockLookup =  (const LookupEntry*)&MemoryMapTextureImage_UnknownRoleInitializedBytes[2];

    LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageFirstMapAddress_260_ = firstBlockLookup[banks].entry << 12;
    LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageSecondMapAddress_274_ = secondBlockLookup[banks].entry << 12;
    LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageFirstMapRegionSize_278_ = thirdBlockLookup[banks].entry << 12;
}

// Original: arm9/main @ 0x020C64FC; symbol: LoadToTextureImage; size: 0x140.
void LoadToTextureImage(const void* data, unsigned int offset, unsigned int length)
{
    unsigned int secondBlockStart = LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageSecondMapAddress_274_;
    unsigned int firstBlockWriteAddr;
    
    // only one region is memory mapped, so only do one write
    if (secondBlockStart == 0)
        firstBlockWriteAddr = LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageFirstMapAddress_260_ + offset;
    // the desired write fits entirely into the first mapped block
    else if (offset + length < LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageFirstMapRegionSize_278_)
        firstBlockWriteAddr = LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageFirstMapAddress_260_ + offset;
    // desired write fits entirely into second mapped block
    else if (offset >= LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageFirstMapRegionSize_278_)
        firstBlockWriteAddr = secondBlockStart + offset - LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageFirstMapRegionSize_278_;
    else // desired write spans both mapped blocks
    {
        firstBlockWriteAddr = LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageFirstMapAddress_260_ + offset;
        unsigned int firstWriteSize = LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageFirstMapRegionSize_278_ - offset;
        
        if (LoadToSubOAM_UnknownRoleInitializedBytes != -1 && firstWriteSize > 48)
            DMAMemcpySynchronous(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, firstBlockWriteAddr, firstWriteSize);
        else
            MIi_CpuCopy32(data, (void*)firstBlockWriteAddr, firstWriteSize);

        if (LoadToSubOAM_UnknownRoleInitializedBytes != -1)
            DMAMemcpyAsync(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data + firstWriteSize, secondBlockStart, length - firstWriteSize, NULL, 0);
        else
            MIi_CpuCopy32((const void*)((unsigned int)data + firstWriteSize), (void*)secondBlockStart, length - firstWriteSize);
        return;
    }

    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1)
        DMAMemcpyAsync(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, firstBlockWriteAddr, length, NULL, 0);
    else
        MIi_CpuCopy32(data, (void*)firstBlockWriteAddr, length);
}

// Original: arm9/main @ 0x020C663C; symbol: MemoryUnmapTextureImage; size: 0x4C.
void MemoryUnmapTextureImage()
{
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1)
        AwaitDMACompletion(LoadToSubOAM_UnknownRoleInitializedBytes);
    MapVRAMBanksToTextureImage(LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageBanks_270_);
    LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageFirstMapRegionSize_278_ = 0;
    LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageSecondMapAddress_274_ = 0;
    LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageFirstMapAddress_260_ = 0;
    LoadClearImage_UnknownRoleZeroInitializedStorage.textureImageBanks_270_ = 0;
}

// Original: arm9/main @ 0x020C6688; symbol: MemoryMapTexturePalette; size: 0x34.
void MemoryMapTexturePalette()
{
    int banks = ReleaseTexturePaletteVRAMBanks();
    LoadClearImage_UnknownRoleZeroInitializedStorage.texturePaletteBanks_268_ = banks;
    LoadClearImage_UnknownRoleZeroInitializedStorage.texturePaletteMapAddress_264_ = MemoryMapTexturePalette_UnknownRoleInitializedBytes[banks >> 4] << 12;
}

// Original: arm9/main @ 0x020C66BC; symbol: LoadToTexturePalette; size: 0x6C.
void LoadToTexturePalette(const void* data, unsigned int offset, unsigned int length)
{
    int dmaChannel = LoadToSubOAM_UnknownRoleInitializedBytes;
    unsigned int writeAddr = LoadClearImage_UnknownRoleZeroInitializedStorage.texturePaletteMapAddress_264_ + offset;
    if (dmaChannel != -1)
        DMAMemcpyAsync(dmaChannel, (unsigned int)data, writeAddr, length, NULL, 0);
    else
        MIi_CpuCopy32(data, (void*)writeAddr, length);
}

// Original: arm9/main @ 0x020C6728; symbol: MemoryUnmapTexturePalette; size: 0x44.
void MemoryUnmapTexturePalette()
{
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1)
        AwaitDMACompletion(LoadToSubOAM_UnknownRoleInitializedBytes);
    MapVRAMBanksToTexturePalette(LoadClearImage_UnknownRoleZeroInitializedStorage.texturePaletteBanks_268_);
    LoadClearImage_UnknownRoleZeroInitializedStorage.texturePaletteBanks_268_ = 0;
    LoadClearImage_UnknownRoleZeroInitializedStorage.texturePaletteMapAddress_264_ = 0;
}

// Original: arm9/main @ 0x020C676C; symbol: MemoryMapClearTexture; size: 0x90.
void MemoryMapClearTexture()
{
    int banks = ReleaseClearTextureVRAMBanks();
    LoadClearImage_UnknownRoleZeroInitializedStorage.clearTextureBanks_25c_ = banks;
    switch (banks)
    {
    case VRAM_BANK_B:
    case VRAM_BANK_A | VRAM_BANK_B:
        LoadClearImage_UnknownRoleZeroInitializedStorage.clearTextureMapAddress_26c_ = 0x06800000;
        break;
    case VRAM_BANK_D:
    case VRAM_BANK_C | VRAM_BANK_D:
        LoadClearImage_UnknownRoleZeroInitializedStorage.clearTextureMapAddress_26c_ = 0x06840000;
        break;
    case VRAM_BANK_A:
        LoadClearImage_UnknownRoleZeroInitializedStorage.clearTextureMapAddress_26c_ = 0x067e0000;
        break;
    case VRAM_BANK_C:
        LoadClearImage_UnknownRoleZeroInitializedStorage.clearTextureMapAddress_26c_ = 0x06820000;
        break;
    }
}

// Original: arm9/main @ 0x020C67FC; symbol: LoadClearImage; size: 0x68.
void LoadClearImage(const void* data, unsigned int length)
{
    int dmaChannel = LoadToSubOAM_UnknownRoleInitializedBytes;
    unsigned int writeAddr = LoadClearImage_UnknownRoleZeroInitializedStorage.clearTextureMapAddress_26c_;
    if (dmaChannel != -1)
        DMAMemcpyAsync(dmaChannel, (unsigned int)data, writeAddr, length, NULL, 0);
    else
        MIi_CpuCopy32(data, (void*)writeAddr, length);
}

// Original: arm9/main @ 0x020C6864; symbol: LoadClearDepthBuffer; size: 0x6C.
void LoadClearDepthBuffer(const void* data, unsigned int length)
{
    unsigned int writeAddr = LoadClearImage_UnknownRoleZeroInitializedStorage.clearTextureMapAddress_26c_ + 0x20000;
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1)
        DMAMemcpyAsync(LoadToSubOAM_UnknownRoleInitializedBytes, (unsigned int)data, writeAddr, length, NULL, 0);
    else
        MIi_CpuCopy32(data, (void*)writeAddr, length);
}

// Original: arm9/main @ 0x020C68D0; symbol: MemoryUnmapClearTexture; size: 0x44.
void MemoryUnmapClearTexture()
{
    if (LoadToSubOAM_UnknownRoleInitializedBytes != -1)
        AwaitDMACompletion(LoadToSubOAM_UnknownRoleInitializedBytes);

    MapVRAMBanksToClearTextures(LoadClearImage_UnknownRoleZeroInitializedStorage.clearTextureBanks_25c_);
    LoadClearImage_UnknownRoleZeroInitializedStorage.clearTextureBanks_25c_ = 0;
    LoadClearImage_UnknownRoleZeroInitializedStorage.clearTextureMapAddress_26c_ = 0;
}
