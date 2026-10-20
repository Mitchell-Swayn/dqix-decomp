#include <globaldefs.h>
// Original: arm9/ov011 @ 0x021863D0; symbol: func_ov011_021863d0; size: 0x1C.
extern "C" void Graphics_WriteBackgroundThreeControlLowBits(unsigned a) { volatile unsigned short* reg=(volatile unsigned short*)0x0400000E; *reg=(*reg & ~3) | a; }
