#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088C9C; symbol: func_02088c9c; size: 0x1C.
extern "C" void CombatantState_ClearIceBarrier(unsigned char* p) { *(unsigned int*)(p+0x18)&=~0x4;p[0x6d]=0;p[0x90]=0; }
