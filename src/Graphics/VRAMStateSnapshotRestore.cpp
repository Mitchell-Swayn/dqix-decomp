#include "Graphics/VRAMAllocations.h"

// Original: arm9/main @ 0x0207DF90; symbol: func_0207df90; size: 0x1C.
extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(const unsigned char* state)
{
    RestoreTextureImageVRAMState((const unsigned int*)(state + 0x28));
    RestoreTexturePaletteVRAMState((const TexturePaletteVRAMState*)(state + 0x60));
}

