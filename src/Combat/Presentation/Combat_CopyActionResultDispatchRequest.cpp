#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021DCD28; symbol: func_ov025_021dcd28; size: 0x34.
extern "C" void Combat_CopyActionResultDispatchRequest(void *out, const void *in) {
    *(unsigned int *)((char *)out + 0x00) = *(const unsigned int *)((const char *)in + 0x00);
    *(unsigned int *)((char *)out + 0x04) = *(const unsigned int *)((const char *)in + 0x04);
    *(unsigned int *)((char *)out + 0x08) = *(const unsigned int *)((const char *)in + 0x08);
    *(unsigned int *)((char *)out + 0x0c) = *(const unsigned int *)((const char *)in + 0x0c);
    *(unsigned int *)((char *)out + 0x10) = *(const unsigned int *)((const char *)in + 0x10);
    *(unsigned char *)((char *)out + 0x14) = *(const unsigned char *)((const char *)in + 0x14);
}
