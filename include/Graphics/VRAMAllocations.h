#pragma once

// The model loader can pass the original NSBXX flag word directly here. Keep
// the argument wide enough to preserve bits such as 0x8000.
typedef unsigned int (*TextureVRAMAllocateCallback)(unsigned int amount,
    unsigned int flags, unsigned int direction);
typedef int (*TextureVRAMFreeCallback)(unsigned int key);
// Original data: arm9/main @ 0x20f1ee8; symbol: data_020f1ee8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 24b40b02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern TextureVRAMAllocateCallback InitializeTextureImageVRAM_UnknownRoleProcedureReferenceRecords;
// Original data: arm9/main @ 0x20f1eec; symbol: data_020f1eec.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 2cb40b02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern TextureVRAMFreeCallback InitializeTextureImageVRAM_UnknownRoleProcedureReferenceRecords_Variant2;
// Original data: arm9/main @ 0x20f1ef0; symbol: data_020f1ef0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 34b40b02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern TextureVRAMAllocateCallback InitializeTexturePaletteVRAM_UnknownRoleProcedureReferenceRecords;
// Original data: arm9/main @ 0x20f1ef4; symbol: data_020f1ef4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 3cb40b02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern TextureVRAMFreeCallback InitializeTexturePaletteVRAM_UnknownRoleProcedureReferenceRecords_Variant2;

// Allocation keys encode the allocation size and offset in units of eight
// bytes. direction == 1 allocates from the low end; other values use the high end.
extern "C" unsigned int AllocateTexturePaletteVRAM(unsigned int amount, unsigned int eightByteAlign, unsigned int direction);
extern "C" int FreeTexturePaletteVRAM(unsigned int key);
void InitializeTexturePaletteVRAM(unsigned int size, bool setDefault);
struct TexturePaletteVRAMState
{
    unsigned int freeStart;
    unsigned int freeEnd;
};
void SaveTexturePaletteVRAMState(TexturePaletteVRAMState* state);
void RestoreTexturePaletteVRAMState(const TexturePaletteVRAMState* state);
void ResetTexturePaletteVRAM();

// The image state stores start/end bounds for each of the five VRAM pools.
extern "C" int FreeTextureImageVRAM(unsigned int key);
void SaveTextureImageVRAMState(unsigned int* state);
void RestoreTextureImageVRAMState(const unsigned int* state);
void ResetTextureImageVRAM();
void SetTextureImageVRAMPoolOrder(int first, int second, int third, int fourth, int fifth);
void InitializeTextureImageVRAM(unsigned int banks, bool setDefault);
