#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F650C; symbol: func_ov023_021f650c; size: 0x18.
extern "C" void func_ov023_021f650c(void *object, unsigned value) {
    unsigned old = *(unsigned char *)((char *)object + 0x3a);
    *(unsigned char *)((char *)object + 0x3a) = (old & 0xffffff0f) | ((value << 28) >> 24);
}
