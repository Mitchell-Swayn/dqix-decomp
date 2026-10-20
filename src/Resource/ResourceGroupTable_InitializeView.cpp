#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x020DF828; symbol: func_020df828; size: 0x14.
extern "C" void* ResourceGroupTable_InitializeView(void* p){return memset(p,0,16);}
