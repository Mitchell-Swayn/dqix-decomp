#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x0206EBC8; symbol: func_0206ebc8; size: 0x14.
extern "C" void* Script_ClearPrimaryMessageUsageCounters(void* p){return memset(p,0,128);}
