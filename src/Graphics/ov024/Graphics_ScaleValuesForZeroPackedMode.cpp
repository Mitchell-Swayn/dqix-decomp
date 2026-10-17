#include <globaldefs.h>
ARM
extern "C" unsigned _fmul(unsigned, unsigned);
// Original: arm9/ov024 @ 0x021F7070; symbol: func_ov024_021f7070; size: 0x4C.
extern "C" int Graphics_ScaleValuesForZeroPackedMode(void *p) {
    unsigned char *base = (unsigned char *)p;
    unsigned char *descriptor = *(unsigned char **)(base + 8);
    if (descriptor && (((unsigned int)*(unsigned short *)(descriptor + 0xa) << 21) >> 28) == 0) {
        *(unsigned *)((char *)p + 0x1c) = _fmul(0x3fc00000, *(unsigned *)((char *)p + 0x14));
        *(unsigned *)((char *)p + 0x20) = _fmul(0x3fc00000, *(unsigned *)((char *)p + 0x18));
    }
    return 1;
}
