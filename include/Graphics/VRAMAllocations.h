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

// The image state stores start/end bounds for each of the five VRAM pools.
extern "C" int FreeTextureImageVRAM(unsigned int key);
void SaveTextureImageVRAMState(unsigned int* state);
void RestoreTextureImageVRAMState(const unsigned int* state);
void ResetTextureImageVRAM();
void SetTextureImageVRAMPoolOrder(int first, int second, int third, int fourth, int fifth);
void InitializeTextureImageVRAM(unsigned int banks, bool setDefault);
