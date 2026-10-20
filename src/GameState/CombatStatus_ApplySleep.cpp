#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088338; symbol: func_02088338; size: 0x58.
extern "C" void CombatStatus_ApplySleep(unsigned char* p){*(unsigned*)(p+20)&=~0x800000U;p[36]=0;*(unsigned*)(p+20)&=~0x80000U;*(unsigned short*)(p+34)&=~0x3c;p[33]=0;*(unsigned*)(p+24)&=~32U;p[93]=1;p[128]=0;*(unsigned*)(p+20)|=16;}
