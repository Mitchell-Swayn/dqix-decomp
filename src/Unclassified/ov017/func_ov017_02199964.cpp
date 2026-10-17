#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x02199964; symbol: func_ov017_02199964; size: 0x34.
extern "C" void func_ov017_02199964(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e) {
    volatile unsigned short *reg = (volatile unsigned short *)0x0400000A;
    *reg = (unsigned short)((*reg & 0x43) | (a << 14) | (b << 7) | (c << 8) | (d << 2) | (e << 13));
}
