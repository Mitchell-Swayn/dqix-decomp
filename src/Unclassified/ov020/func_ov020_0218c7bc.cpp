#include <globaldefs.h>
ARM
// Original: arm9/ov020 @ 0x0218C7BC; symbol: func_ov020_0218c7bc; size: 0x34.
extern "C" void func_ov020_0218c7bc(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e) {
    *(volatile unsigned short*)0x0400000A = (unsigned short)((*(volatile unsigned short*)0x0400000A & 0x43) | (a << 14) | (b << 7) | (c << 8) | (d << 2) | (e << 13));
}
