#include <globaldefs.h>
ARM
extern "C" int func_ov031_0221b6f0(unsigned int, unsigned int, unsigned int);
extern "C" unsigned int data_ov031_0224e6a0[];
// Original: arm9/ov031 @ 0x0221AFB4; symbol: func_ov031_0221afb4; size: 0x44.
extern "C" int ProcessorContext_SetScaledSharedOffsetIfValid(void *context) {
    if (func_ov031_0221b6f0(0x20, 0x20, (unsigned int)context) == 0) return 0;
    data_ov031_0224e6a0[2] = (*(unsigned short *)context << 3) - 0x400;
    return 1;
}
