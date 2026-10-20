#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0208C9CC; symbol: func_0208c9cc; size: 0x34.
extern "C" void Graphics_WriteSubBG0ControlBits(unsigned int a,unsigned int b,unsigned int c,unsigned int d,unsigned int e) { volatile unsigned short* reg=(volatile unsigned short*)0x04001008;*reg=(*reg&0x43)|(a<<14)|(b<<7)|(c<<8)|(d<<2)|(e<<13); }
