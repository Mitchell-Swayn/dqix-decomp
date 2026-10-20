#include <globaldefs.h>
ARM
extern "C" void MemoryMapSubBGExtendedPalette();extern "C" void LoadToSubBGExtendedPalette(const void*,unsigned,unsigned);extern "C" void MemoryUnmapSubBGExtendedPalette();
// Original: arm9/main @ 0x020BBBF4; symbol: func_020bbbf4; size: 0x2C.
extern "C" void Graphics_LoadSubBGExtendedPaletteWithMapping(const void* source,unsigned offset,unsigned size){MemoryMapSubBGExtendedPalette();LoadToSubBGExtendedPalette(source,offset,size);MemoryUnmapSubBGExtendedPalette();}
