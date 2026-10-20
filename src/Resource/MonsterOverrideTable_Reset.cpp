#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x020A8E88; symbol: func_020a8e88; size: 0x14.
extern "C" void* MonsterOverrideTable_Reset(void* p){return memset(p,0,12);}
