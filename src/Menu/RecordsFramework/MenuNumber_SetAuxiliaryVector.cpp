#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FBCD4; symbol: func_ov023_021fbcd4; size: 0x1C.
extern "C" void MenuNumber_SetAuxiliaryVector(void *dst, const unsigned int *src) {
    *(unsigned int *)((unsigned char *)dst + 0x20) = src[0];
    *(unsigned int *)((unsigned char *)dst + 0x24) = src[1];
    *(unsigned int *)((unsigned char *)dst + 0x28) = src[2];
}
