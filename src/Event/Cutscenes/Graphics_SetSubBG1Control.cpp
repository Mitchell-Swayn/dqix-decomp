#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x0215E78C; symbol: func_ov001_0215e78c; size: 0x34.
extern "C" void Graphics_SetSubBG1Control(unsigned int size, unsigned int color, unsigned int screenBase, unsigned int charBase, unsigned int extendedPalette) {
    *(volatile unsigned short *)0x0400100a = (*(volatile unsigned short *)0x0400100a & 0x43) | (size << 14) | (color << 7) | (screenBase << 8) | (charBase << 2) | (extendedPalette << 13);
}
