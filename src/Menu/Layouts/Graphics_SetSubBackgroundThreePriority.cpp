#include <globaldefs.h>
// Original: arm9/ov011 @ 0x02186360; symbol: func_ov011_02186360; size: 0x1C.
extern "C" void Graphics_SetSubBackgroundThreePriority(unsigned a) { volatile unsigned short* reg=(volatile unsigned short*)0x0400100E; *reg=(*reg & ~3) | a; }
