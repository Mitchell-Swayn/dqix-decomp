#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F7158; symbol: func_ov023_021f7158; size: 0x1C.
extern "C" void func_ov023_021f7158(void *destination, const void *source) {
    *(unsigned int *)((unsigned char *)destination + 0x3c) = *(const unsigned int *)source;
    *(unsigned int *)((unsigned char *)destination + 0x40) = *(const unsigned int *)((const unsigned char *)source + 4);
    *(unsigned int *)((unsigned char *)destination + 0x44) = *(const unsigned int *)((const unsigned char *)source + 8);
}
