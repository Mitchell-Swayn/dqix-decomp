#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x0204BF30; symbol: func_0204bf30; size: 0x14.
extern "C" void* ZoneCollision_ResetResource(void* p){return memset(p,0,76);}
