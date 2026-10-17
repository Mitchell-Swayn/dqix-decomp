#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088BB4; symbol: func_02088bb4; size: 0x20.
extern "C" void Object_SetByte69ToSixAndFlag80000000(unsigned char* p) { p[0x69]=6;p[0x8c]=0;*(unsigned int*)(p+0x14)|=0x80000000; }
