#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x0202099C; symbol: func_0202099c; size: 0x34.
void Graphics_WriteSubBackgroundControlBits(unsigned int a,unsigned int b,unsigned int c,unsigned int d,unsigned int e){*(volatile unsigned short *)0x0400100a=(*(volatile unsigned short *)0x0400100a&0x43)|(a<<14)|(b<<7)|(c<<8)|(d<<2)|(e<<13);}
}
