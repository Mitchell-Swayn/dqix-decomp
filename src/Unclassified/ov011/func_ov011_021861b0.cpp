#include <globaldefs.h>
// Original: arm9/ov011 @ 0x021861B0; symbol: func_ov011_021861b0; size: 0x34.
extern "C" void func_ov011_021861b0(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e) { volatile unsigned short* reg=(volatile unsigned short*)0x04001008; *reg=(*reg & 0x43) | (a<<14) | (b<<7) | (c<<8) | (d<<2) | (e<<13); }
