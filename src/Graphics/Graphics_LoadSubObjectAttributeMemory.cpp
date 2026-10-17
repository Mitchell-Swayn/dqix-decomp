#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void LoadToSubOAM(const void*,unsigned,unsigned);
// Original: arm9/main @ 0x020BBC20; symbol: func_020bbc20; size: 0xC.
extern "C" void Graphics_LoadSubObjectAttributeMemory(const void* data,unsigned offset,unsigned length){LoadToSubOAM(data,offset,length);}
