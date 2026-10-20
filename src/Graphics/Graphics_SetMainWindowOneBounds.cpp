#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020E2A20; symbol: func_020e2a20; size: 0x34.
extern "C" void Graphics_SetMainWindowOneBounds(unsigned a,unsigned b,unsigned c,unsigned d){volatile unsigned short* reg=(volatile unsigned short*)0x04000042;reg[0]=((a<<8)&0xff00)|(c&255);reg[2]=((b<<8)&0xff00)|(d&255);}
