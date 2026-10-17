#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02020968; symbol: func_02020968; size: 0x34.
extern "C" void SubBackground1_ConfigureControlBits(unsigned int a,unsigned int b,unsigned int c,unsigned int d,unsigned int e) { volatile unsigned short* reg=(volatile unsigned short*)0x04001008;*reg=(*reg&0x43)|(a<<14)|(b<<7)|(c<<8)|(d<<2)|(e<<13); }
