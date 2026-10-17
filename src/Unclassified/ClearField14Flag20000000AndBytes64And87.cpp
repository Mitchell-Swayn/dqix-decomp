#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088A54; symbol: func_02088a54; size: 0x1C.
extern "C" void ClearField14Flag20000000AndBytes64And87(unsigned char* p) { *(unsigned int*)(p+0x14)&=~0x20000000;p[0x64]=0;p[0x87]=0; }
