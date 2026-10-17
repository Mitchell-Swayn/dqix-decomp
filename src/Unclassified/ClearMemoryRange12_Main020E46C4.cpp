#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x020E46C4; symbol: func_020e46c4; size: 0x14.
extern "C" void* ClearMemoryRange12_Main020E46C4(void* p){return memset(p,0,12);}
