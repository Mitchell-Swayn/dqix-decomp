#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x021553A8; symbol: func_ov006_021553a8; size: 0x14.
extern "C" void SetFlagBit3AtOffsetAE2(void *object) {
    unsigned short *flags = (unsigned short *)((char *)object + 0xae2);
    *flags |= 8;
}
