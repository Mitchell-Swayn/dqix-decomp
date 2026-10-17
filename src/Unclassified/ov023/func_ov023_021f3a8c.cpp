#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F3A8C; symbol: func_ov023_021f3a8c; size: 0x20.
extern "C" int func_ov023_021f3a8c(unsigned char *p) {
    unsigned int sentinel = 0xffffffffu;
    return *(unsigned int *)(p + 0x64) == sentinel && *(unsigned int *)(p + 0x68) == sentinel;
}
