#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088944; symbol: func_02088944; size: 0x20.
extern "C" void Object_SetByte66ToFiveAndFlag4000000(unsigned char* p) { p[0x66]=5;p[0x89]=0;*(unsigned int*)(p+0x14)|=0x4000000; }
