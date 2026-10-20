#include <globaldefs.h>
ARM
extern "C" void MemoryMapMainObjExtendedPalette();extern "C" void LoadToMainObjExtendedPalette(const void*,unsigned,unsigned);extern "C" void MemoryUnmapMainObjExtendedPalette();
// Original: arm9/main @ 0x020BBAC8; symbol: func_020bbac8; size: 0x2C.
extern "C" void Graphics_MapLoadAndUnmapMainObjectExtendedPalette(const void* source,unsigned offset,unsigned size){MemoryMapMainObjExtendedPalette();LoadToMainObjExtendedPalette(source,offset,size);MemoryUnmapMainObjExtendedPalette();}
