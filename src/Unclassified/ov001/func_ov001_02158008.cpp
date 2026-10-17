#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x02158008; symbol: func_ov001_02158008; size: 0x10.
extern "C" int func_ov001_02158008(void *src, void *dst) {
    *(unsigned int *)((unsigned char *)dst + 0x64) = *(unsigned int *)((unsigned char *)src + 0x1c);
    return 0;
}
