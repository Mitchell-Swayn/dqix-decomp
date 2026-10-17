#include <globaldefs.h>
// Original: arm9/ov011 @ 0x02186150; symbol: func_ov011_02186150; size: 0x2C.
extern "C" void func_ov011_02186150(unsigned a, unsigned b, unsigned c, unsigned d) { volatile unsigned short* reg=(volatile unsigned short*)0x0400100C; *reg=(*reg & 0x43) | (a<<14) | (b<<7) | (c<<8) | (d<<2); }
