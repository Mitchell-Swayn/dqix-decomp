#include <globaldefs.h>
// Original: arm9/ov011 @ 0x02186408; symbol: func_ov011_02186408; size: 0x1C.
extern "C" void func_ov011_02186408(unsigned a) { volatile unsigned short* reg=(volatile unsigned short*)0x0400000A; *reg=(*reg & ~3) | a; }
