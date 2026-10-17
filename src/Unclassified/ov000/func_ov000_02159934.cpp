#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02159934; symbol: func_ov000_02159934; size: 0x18.
extern "C" int func_ov000_02159934(void *p) {
    void *q = *(void **)((char *)p + 0x138);
    return (*(unsigned int *)((char *)q + 0x14) & 0x800) != 0;
}
