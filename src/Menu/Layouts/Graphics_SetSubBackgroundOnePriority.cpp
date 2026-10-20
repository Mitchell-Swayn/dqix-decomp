#include <globaldefs.h>
// Original: arm9/ov011 @ 0x02186398; symbol: func_ov011_02186398; size: 0x1C.
extern "C" void Graphics_SetSubBackgroundOnePriority(unsigned a) { volatile unsigned short* reg=(volatile unsigned short*)0x0400100A; *reg=(*reg & ~3) | a; }
