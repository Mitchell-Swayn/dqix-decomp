#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0216872C; symbol: func_ov000_0216872c; size: 0x10.
extern "C" void func_ov000_0216872c(void *base, unsigned char first, unsigned char second) {
    unsigned char *p = (unsigned char *)base + 0x7000;
    p[0x7d3] = first;
    p[0x7d4] = second;
}
