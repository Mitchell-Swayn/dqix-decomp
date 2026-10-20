#include <globaldefs.h>
ARM
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F6DD4; symbol: Math_DoubleObjectFloatFields14And18Into1CAnd20; size: 0x30.
// Multiplies float words at offsets +0x14 and +0x18 by 2.0 and stores them at +0x1c and +0x20.
extern "C" int Math_DoubleObjectFloatFields14And18Into1CAnd20(void *obj) {
    unsigned int x = *(unsigned int *)((char *)obj + 0x14);
    *(unsigned int *)((char *)obj + 0x1c) = _fmul(0x40000000, x);
    unsigned int y = *(unsigned int *)((char *)obj + 0x18);
    *(unsigned int *)((char *)obj + 0x20) = _fmul(0x40000000, y);
    return 1;
}
