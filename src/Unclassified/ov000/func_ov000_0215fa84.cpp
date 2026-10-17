#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0215FA84; symbol: func_ov000_0215fa84; size: 0x20.
extern "C" void func_ov000_0215fa84(void *object, short *first, short *second, short *third) {
    *first = *(short *)((unsigned char *)object + 0x8e4a);
    *second = *(short *)((unsigned char *)object + 0x8e4c);
    *third = *(short *)((unsigned char *)object + 0x8e4e);
}
