#include <globaldefs.h>
ARM
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F6FEC; symbol: func_ov024_021f6fec; size: 0x50.
extern "C" int func_ov024_021f6fec(void *p) {
    void *nested = *(void **)((char *)p + 8);
    if (nested != 0 && (( ((unsigned int)*(unsigned short *)((char *)nested + 0xa)) << 21) >> 28) == 6) {
        *(unsigned int *)((char *)p + 0x1c) = _fmul(0x3fc00000, *(unsigned int *)((char *)p + 0x14));
        *(unsigned int *)((char *)p + 0x20) = _fmul(0x3fc00000, *(unsigned int *)((char *)p + 0x18));
    }
    return 1;
}
