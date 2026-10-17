#include <globaldefs.h>
// Original: arm9/ov011 @ 0x021863EC; symbol: func_ov011_021863ec; size: 0x1C.
extern "C" void func_ov011_021863ec(unsigned a) { volatile unsigned short* reg=(volatile unsigned short*)0x0400000C; *reg=(*reg & ~3) | a; }
