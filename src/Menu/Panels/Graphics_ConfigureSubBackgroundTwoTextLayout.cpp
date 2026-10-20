#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021EC39C; symbol: System_SetHardwareControlBitsAt0400100C; size: 0x2C.
// Preserves bits selected by 0x43 in hardware halfword 0x0400100C and inserts four arguments at shifts 14, 7, 8, and 2.
extern "C" void Graphics_ConfigureSubBackgroundTwoTextLayout(unsigned a, unsigned b, unsigned c, unsigned d) {
    volatile unsigned short *reg = (volatile unsigned short *)0x0400100c;
    *reg = (unsigned short)((*reg & 0x43) | (a << 14) | (b << 7) | (c << 8) | (d << 2));
}
