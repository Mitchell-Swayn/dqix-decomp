#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088234; symbol: func_02088234; size: 0x18.
extern "C" void ClearWord14Bit23AndByte24(unsigned char* p) { *(unsigned int*)(p+0x14)&=~0x800000; p[0x24]=0; }
