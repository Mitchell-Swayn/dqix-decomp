#include <globaldefs.h>
ARM
#include <System/LoadToVRAM.h>
// Original: arm9/main @ 0x020BB9C4; symbol: func_020bb9c4; size: 0x2C.
extern "C" void Graphics_MapLoadAndUnmapTexturePalette(const void* data,unsigned int offset,unsigned int length){MemoryMapTexturePalette();LoadToTexturePalette(data,offset,length);MemoryUnmapTexturePalette();}
