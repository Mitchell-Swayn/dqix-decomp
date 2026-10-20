#include <globaldefs.h>
ARM
// Original: arm9/ov020 @ 0x0218CD64; symbol: func_ov020_0218cd64; size: 0x34.
extern "C" void Graphics_SetDisplayControlBits(int a, int b, int c, int d, int e) {
    volatile unsigned short *p = (volatile unsigned short *)0x04001008;
    *p = (unsigned short)((*p & 0x43) | (a << 14) | (b << 7) | (c << 8) | (d << 2) | (e << 13));
}
