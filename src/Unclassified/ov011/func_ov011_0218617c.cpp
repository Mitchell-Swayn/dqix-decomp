#include <globaldefs.h>
// Original: arm9/ov011 @ 0x0218617C; symbol: func_ov011_0218617c; size: 0x34.
extern "C" void func_ov011_0218617c(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e) { volatile unsigned short* reg=(volatile unsigned short*)0x0400100A; *reg=(*reg & 0x43) | (a<<14) | (b<<7) | (c<<8) | (d<<2) | (e<<13); }
