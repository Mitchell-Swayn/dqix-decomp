#include <globaldefs.h>
// Original: arm9/ov011 @ 0x0218637C; symbol: func_ov011_0218637c; size: 0x1C.
extern "C" void Graphics_SetSubBackgroundTwoPriority(unsigned a) { volatile unsigned short* reg=(volatile unsigned short*)0x0400100C; *reg=(*reg & ~3) | a; }
