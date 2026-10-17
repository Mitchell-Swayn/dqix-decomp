#include <globaldefs.h>
ARM

extern "C" unsigned int _fmul(unsigned int, unsigned int);

// Original: arm9/ov024 @ 0x021F7100; symbol: func_ov024_021f7100; size: 0x50.
extern "C" int World_ScaleFieldsForSubtype4(void *self) {
    if (*(void **)((char *)self + 8) != 0) {
        unsigned int subtype = *(unsigned short *)((char *)*(void **)((char *)self + 8) + 0xa);
        subtype = (subtype << 21) >> 28;
        if (subtype == 4) {
            *(unsigned int *)((char *)self + 0x1c) = _fmul(0x3fc00000, *(unsigned int *)((char *)self + 0x14));
            *(unsigned int *)((char *)self + 0x20) = _fmul(0x3fc00000, *(unsigned int *)((char *)self + 0x18));
        }
    }
    return 1;
}
