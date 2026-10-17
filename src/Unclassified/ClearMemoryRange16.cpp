#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x020DF83C; symbol: func_020df83c; size: 0x14.
extern "C" void* ClearMemoryRange16(void* p){return memset(p,0,16);}
