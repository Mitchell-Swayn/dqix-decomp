#include <globaldefs.h>
ARM

extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" unsigned long long _Z19GetCurrentTimestampv();

// Original: arm9/ov023 @ 0x021DB0D4; symbol: func_ov023_021db0d4; size: 0x3C.
extern "C" void func_ov023_021db0d4(unsigned char *p, unsigned char value) {
    p[0x24] = value;
    *(unsigned short *)(p + 0x20) = 0;
    *(unsigned short *)(p + 0x22) = 0;
    memset(p, 0, 0x18);
    *(unsigned short *)(p + 2) = 0xf;
    *(unsigned short *)(p + 0xa) = 0xf;
    *(unsigned short *)(p + 0x12) = 0x17;
    _Z19GetCurrentTimestampv();
}
