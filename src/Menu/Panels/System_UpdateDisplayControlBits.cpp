#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021EC3F4; symbol: func_ov023_021ec3f4; size: 0x2C.
extern "C" void System_UpdateDisplayControlBits(unsigned int a, unsigned int b, unsigned int c, unsigned int d) { volatile unsigned short* reg = (volatile unsigned short*)0x0400000e; *reg = (*reg & 0x43) | (a << 14) | (b << 7) | (c << 8) | (d << 2); }
