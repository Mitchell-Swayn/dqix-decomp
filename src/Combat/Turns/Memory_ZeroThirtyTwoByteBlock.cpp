#include <globaldefs.h>
ARM
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov000 @ 0x0215FD7C; symbol: func_ov000_0215fd7c; size: 0x14.
extern "C" void *Memory_ZeroThirtyTwoByteBlock(void *p) {
    return memset(p, 0, 0x20);
}
