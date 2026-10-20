#include <globaldefs.h>
#include "System/LoadToVRAM.h"

// Original: arm9/main @ 0x020BBBC8; symbol: func_020bbbc8; size: 0x2C.
extern "C" void Object_InvokeMemoryMapSubObjExtendedPalette(const void* data, unsigned int offset, unsigned int length)
{
    MemoryMapSubObjExtendedPalette();
    LoadToSubObjExtendedPalette(data, offset, length);
    MemoryUnmapSubObjExtendedPalette();
}
