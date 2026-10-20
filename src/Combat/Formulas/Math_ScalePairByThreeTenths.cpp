#include <globaldefs.h>
ARM
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F6E54; symbol: func_ov024_021f6e54; size: 0x34.
extern "C" int Math_ScalePairByThreeTenths(void *arg) {
    *(unsigned int *)((char *)arg + 0x1C) = _fmul(0x3E99999A, *(unsigned int *)((char *)arg + 0x14));
    *(unsigned int *)((char *)arg + 0x20) = _fmul(0x3E99999A, *(unsigned int *)((char *)arg + 0x18));
    return 1;
}
