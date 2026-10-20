#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x0206EFC4; symbol: func_0206efc4; size: 0x14.
extern "C" void* MonsterData_ClearView(void* p){return memset(p,0,12);}
