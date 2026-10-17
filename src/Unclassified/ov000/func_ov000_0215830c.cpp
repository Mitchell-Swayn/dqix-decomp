#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0215830C; symbol: func_ov000_0215830c; size: 0x18.
extern "C" int func_ov000_0215830c(void *p) {
    void *q = *(void **)((char *)p + 0x138);
    return (*(unsigned int *)((char *)q + 0x14) & 0x40000000) != 0;
}
