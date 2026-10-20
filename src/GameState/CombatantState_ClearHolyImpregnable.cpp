#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088CF4; symbol: func_02088cf4; size: 0x1C.
extern "C" void CombatantState_ClearHolyImpregnable(unsigned char* p) { *(unsigned int*)(p+0x18)&=~0x8;p[0x6b]=0;p[0x8e]=0; }
