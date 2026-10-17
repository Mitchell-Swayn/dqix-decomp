#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F8CD4; symbol: func_ov023_021f8cd4; size: 0x1C.
extern "C" void func_ov023_021f8cd4(void *dest, const void *src) {
    *(int *)((char *)dest + 0x24) = *(const int *)src;
    *(int *)((char *)dest + 0x28) = *(const int *)((const char *)src + 4);
    *(int *)((char *)dest + 0x2c) = *(const int *)((const char *)src + 8);
}
