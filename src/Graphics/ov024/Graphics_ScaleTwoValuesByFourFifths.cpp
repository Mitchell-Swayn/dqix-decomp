#include <globaldefs.h>
ARM
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F703C; symbol: func_ov024_021f703c; size: 0x34.
extern "C" int Graphics_ScaleTwoValuesByFourFifths(void *p) {
    unsigned int scale = 0x3f4ccccd;
    *(unsigned int *)((char *)p + 0x1c) = _fmul(scale, *(unsigned int *)((char *)p + 0x14));
    *(unsigned int *)((char *)p + 0x20) = _fmul(scale, *(unsigned int *)((char *)p + 0x18));
    return 1;
}
