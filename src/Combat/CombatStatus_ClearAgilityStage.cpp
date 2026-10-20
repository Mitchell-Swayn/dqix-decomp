#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02087A20; symbol: func_02087a20; size: 0x28.
extern "C" void CombatStatus_ClearAgilityStage(unsigned char* p) { *(unsigned int*)(p+0x14)&=~0x1000; *(unsigned int*)(p+0x58)&=~0x1c0;p[0x70]=0;p[0x93]=0; }
