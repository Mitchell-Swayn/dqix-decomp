#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021EC454; symbol: func_ov023_021ec454; size: 0x2C.
extern "C" void Graphics_ConfigureBackground2Control(unsigned int size, unsigned int colorMode, unsigned int screenBase, unsigned int characterBase) {
    volatile unsigned short *reg = (volatile unsigned short *)0x0400000c;
    unsigned int value = *reg & 0x43;
    value |= size << 14;
    value |= colorMode << 7;
    value |= screenBase << 8;
    value |= characterBase << 2;
    *reg = (unsigned short)value;
}
