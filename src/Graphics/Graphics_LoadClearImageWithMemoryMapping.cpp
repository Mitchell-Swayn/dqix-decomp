#include <globaldefs.h>
ARM
extern "C" void MemoryMapClearTexture();extern "C" void LoadClearImage(void*,unsigned);extern "C" void MemoryUnmapClearTexture();
// Original: arm9/main @ 0x020BB9F0; symbol: func_020bb9f0; size: 0x24.
extern "C" void Graphics_LoadClearImageWithMemoryMapping(void* p,unsigned ignored,unsigned size){MemoryMapClearTexture();LoadClearImage(p,size);MemoryUnmapClearTexture();}
