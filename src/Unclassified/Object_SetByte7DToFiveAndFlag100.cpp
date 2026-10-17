#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088D7C; symbol: func_02088d7c; size: 0x20.
extern "C" void Object_SetByte7DToFiveAndFlag100(unsigned char* p) { p[0x7d]=5;p[0xa0]=0;*(unsigned int*)(p+0x18)|=0x100; }
