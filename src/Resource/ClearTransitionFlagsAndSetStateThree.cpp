#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void CombatStatus_ClearSleep(void*);extern "C" void CombatStatus_ClearConfusion(void*);
// Original: arm9/main @ 0x0208826C; symbol: func_0208826c; size: 0x70.
extern "C" void ClearTransitionFlagsAndSetStateThree(unsigned char* p){*(unsigned*)(p+20)&=~0x800000U;p[36]=0;CombatStatus_ClearSleep(p);*(unsigned*)(p+20)&=~0x80000U;*(unsigned short*)(p+34)&=~60;CombatStatus_ClearConfusion(p);p[33]=0;*(unsigned*)(p+24)&=~32U;p[92]=3;p[127]=0;*(unsigned*)(p+20)|=8;}
