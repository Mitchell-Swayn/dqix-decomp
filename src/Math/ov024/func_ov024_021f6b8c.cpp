#include <globaldefs.h>
ARM
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F6B8C; symbol: func_ov024_021f6b8c; size: 0x34.
extern "C" int func_ov024_021f6b8c(void *obj) {
    *(unsigned int *)((char *)obj + 0x1c) = _fmul(0x3fa00000, *(unsigned int *)((char *)obj + 0x14));
    *(unsigned int *)((char *)obj + 0x20) = _fmul(0x3fa00000, *(unsigned int *)((char *)obj + 0x18));
    return 1;
}
