#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021EC3C8; symbol: func_ov023_021ec3c8; size: 0x2C.
extern "C" void System_UpdateDisplayControlFields(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    volatile unsigned short *reg = (volatile unsigned short *)0x0400100e;
    unsigned int value = *reg & 0x43;
    value |= a << 14;
    value |= b << 7;
    value |= c << 8;
    value |= d << 2;
    *reg = (unsigned short)value;
}
