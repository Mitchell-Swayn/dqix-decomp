#include <globaldefs.h>
ARM
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F6ED8; symbol: func_ov024_021f6ed8; size: 0x38.
extern "C" int Math_ScalePairByThreeTenthsAndOneTenth(void *arg) {
    *(unsigned int *)((char *)arg + 0x1C) = _fmul(0x3E99999A, *(unsigned int *)((char *)arg + 0x14));
    *(unsigned int *)((char *)arg + 0x20) = _fmul(0x3DCCCCCD, *(unsigned int *)((char *)arg + 0x18));
    return 1;
}
