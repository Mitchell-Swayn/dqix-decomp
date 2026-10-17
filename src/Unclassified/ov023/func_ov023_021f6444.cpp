#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F6444; symbol: func_ov023_021f6444; size: 0x18.
extern "C" void func_ov023_021f6444(unsigned char *p, unsigned int value) {
    unsigned int old = p[0x44];
    old &= 0xffffff0f;
    value <<= 0x1c;
    p[0x44] = old | (value >> 24);
}
