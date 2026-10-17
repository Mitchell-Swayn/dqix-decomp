#include <globaldefs.h>
// Original: arm9/ov011 @ 0x02187F4C; symbol: func_ov011_02187f4c; size: 0x1C.
extern "C" void func_ov011_02187f4c(unsigned a) { volatile unsigned short* reg=(volatile unsigned short*)0x04000304; *reg=(*reg & ~0x8000) | (a << 15); }
