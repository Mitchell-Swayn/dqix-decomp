#pragma once

// Allocation keys encode the allocation size and offset in units of eight
// bytes. direction == 1 allocates from the low end; other values use the high end.
extern "C" unsigned int AllocateTexturePaletteVRAM(unsigned int amount, bool eightByteAlign, unsigned int direction);
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
