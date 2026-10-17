#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088E64; symbol: func_02088e64; size: 0x1C.
extern "C" void ClearField18Flag1000AndBytes7EAndA1(unsigned char* p) { *(unsigned int*)(p+0x18)&=~0x1000;p[0x7e]=0;p[0xa1]=0; }
