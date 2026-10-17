#include <globaldefs.h>
// Original: arm9/ov011 @ 0x021863B4; symbol: func_ov011_021863b4; size: 0x1C.
extern "C" void func_ov011_021863b4(unsigned a) { volatile unsigned short* reg=(volatile unsigned short*)0x04001008; *reg=(*reg & ~3) | a; }
