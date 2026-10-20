#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088964; symbol: func_02088964; size: 0x1C.
extern "C" void CombatStatus_ClearReverseCycle(unsigned char* p) { *(unsigned int*)(p+0x14)&=~0x4000000;p[0x66]=0;p[0x89]=0; }
