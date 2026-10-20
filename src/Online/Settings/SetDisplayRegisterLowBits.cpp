#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02229C1C; symbol: func_ov031_02229c1c; size: 0x68.
extern "C" void SetDisplayRegisterLowBits(void) {
    volatile unsigned short *r0 = (volatile unsigned short *)0x04001008;
    volatile unsigned short *r1 = (volatile unsigned short *)0x0400000a;
    *r0 = (unsigned short)((*r0 & ~3u) | 3u);
    r0[1] = (unsigned short)((r0[1] & ~3u) | 3u);
    *(volatile unsigned short *)0x04000008 = (unsigned short)((*(volatile unsigned short *)0x04000008 & ~3u) | 3u);
    *r1 = (unsigned short)((*r1 & ~3u) | 3u);
    r1[1] = (unsigned short)((r1[1] & ~3u) | 3u);
}
