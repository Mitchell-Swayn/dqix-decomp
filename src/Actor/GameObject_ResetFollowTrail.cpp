#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x02039D24; symbol: func_02039d24; size: 0x24.
extern "C" void* GameObject_ResetFollowTrail(unsigned char* p){p[459]=0;p[460]=0;p[461]=0;return memset(p+464,0,128);}
