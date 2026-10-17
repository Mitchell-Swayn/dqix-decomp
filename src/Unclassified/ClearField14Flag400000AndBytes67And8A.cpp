#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088B34; symbol: func_02088b34; size: 0x1C.
extern "C" void ClearField14Flag400000AndBytes67And8A(unsigned char* p) { *(unsigned int*)(p+0x14)&=~0x400000;p[0x67]=0;p[0x8a]=0; }
