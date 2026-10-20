#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x0215E758; symbol: func_ov001_0215e758; size: 0x34.
// Updates the sub-engine BG0 control mode, mosaic, color and screen-base fields.
extern "C" void Graphics_SetSubBg0Control(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e) {
    *(volatile unsigned short *)0x04001008 = (*(volatile unsigned short *)0x04001008 & 0x43) | (a << 14) | (b << 7) | (c << 8) | (d << 2) | (e << 13);
}
