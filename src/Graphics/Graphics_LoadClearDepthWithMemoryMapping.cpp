#include "System/LoadToVRAM.h"
// Original: arm9/main @ 0x020BBA14; symbol: func_020bba14; size: 0x24.
extern "C" void Graphics_LoadClearDepthWithMemoryMapping(const void* data, unsigned int ignored, unsigned int length)
{
    MemoryMapClearTexture();
    LoadClearDepthBuffer(data, length);
    MemoryUnmapClearTexture();
}
