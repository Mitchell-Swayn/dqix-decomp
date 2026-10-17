#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0215997C; symbol: func_ov000_0215997c; size: 0x18.
extern "C" int func_ov000_0215997c(void *p) {
    unsigned int value = *(unsigned int *)(*(unsigned char **)((unsigned char *)p + 0x138) + 0x14);
    return (value & 0x4000) != 0;
}
