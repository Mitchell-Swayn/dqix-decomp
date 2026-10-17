#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x0215941C; symbol: func_ov001_0215941c; size: 0x10.
extern "C" int func_ov001_0215941c(void *src, void *dst) {
    *(unsigned int *)((unsigned char *)dst + 0x1dc) = *(unsigned int *)((unsigned char *)src + 0x10);
    return 0;
}
