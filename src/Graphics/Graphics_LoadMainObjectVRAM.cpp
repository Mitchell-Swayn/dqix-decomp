#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void LoadToMainObjVRAM(const void*,unsigned,unsigned);
// Original: arm9/main @ 0x020BBB2C; symbol: func_020bbb2c; size: 0xC.
extern "C" void Graphics_LoadMainObjectVRAM(const void* data,unsigned offset,unsigned length){LoadToMainObjVRAM(data,offset,length);}
