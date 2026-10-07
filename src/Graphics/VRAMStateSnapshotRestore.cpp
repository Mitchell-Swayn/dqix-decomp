#include "Graphics/VRAMAllocations.h"

extern "C" void func_0207df90(const unsigned char* state)
{
    RestoreTextureImageVRAMState((const unsigned int*)(state + 0x28));
    RestoreTexturePaletteVRAMState((const TexturePaletteVRAMState*)(state + 0x60));
}

extern "C" void func_0207dfac(unsigned char* state)
{
    SaveTextureImageVRAMState((unsigned int*)(state + 0x28));
    SaveTexturePaletteVRAMState((TexturePaletteVRAMState*)(state + 0x60));
}
