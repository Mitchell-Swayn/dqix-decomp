#include <globaldefs.h>
// Original: arm9/ov011 @ 0x02186424; symbol: func_ov011_02186424; size: 0x1C.
extern "C" void func_ov011_02186424(unsigned a) { volatile unsigned short* reg=(volatile unsigned short*)0x04000008; *reg=(*reg & ~3) | a; }
