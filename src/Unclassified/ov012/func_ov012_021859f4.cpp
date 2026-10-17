#include <globaldefs.h>
// Test whether an unsigned byte occurs in a bounded sequence. The first
// incoming register is an unused object/context pointer.
// Original: arm9/ov012 @ 0x021859F4; symbol: func_ov012_021859f4; size: 0x30.
extern "C" int func_ov012_021859f4(void*, const unsigned char* bytes, int count, int value)
{
    for (int i = 0; i < count; ++i, ++bytes)
        if (*bytes == value) return 1;
    return 0;
}
