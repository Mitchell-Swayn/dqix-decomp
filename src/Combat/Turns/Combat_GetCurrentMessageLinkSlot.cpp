#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0215E9B8; symbol: func_ov000_0215e9b8; size: 0x20.
extern "C" void *Combat_GetCurrentMessageLinkSlot(void *a0) {
    unsigned char index = *(unsigned char *)((char *)a0 + 0x8e03);
    if (index >= 0xfc)
        return 0;
    return (char *)a0 + 0x5480 + index * 8;
}
