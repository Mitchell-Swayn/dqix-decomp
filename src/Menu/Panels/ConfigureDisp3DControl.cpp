#include <globaldefs.h>
ARM

// Original: arm9/ov023 @ 0x021EC420; symbol: func_ov023_021ec420; size: 0x34.
extern "C" void ConfigureDisp3DControl(int a, int b, int c, int d, int e) {
    volatile unsigned short *reg = (volatile unsigned short *)0x0400000a;
    *reg = (*reg & 0x43) | (a << 14) | (b << 7) | (c << 8) | (d << 2) | (e << 13);
}
