#include <globaldefs.h>
ARM
// Original: arm9/ov002 @ 0x021556EC; symbol: func_ov002_021556ec; size: 0x10.
extern "C" void func_ov002_021556ec(void *base, unsigned char first, unsigned char second) {
    unsigned char *p = (unsigned char *)base + 0x2000;
    p[0x485] = first;
    p[0x486] = second;
}
