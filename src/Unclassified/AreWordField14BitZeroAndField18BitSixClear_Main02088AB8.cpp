#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088AB8; symbol: func_02088ab8; size: 0x24.
extern "C" bool AreWordField14BitZeroAndField18BitSixClear_Main02088AB8(unsigned int* p) { if (p[5]&1) return false; return (p[6]&0x40)==0; }
