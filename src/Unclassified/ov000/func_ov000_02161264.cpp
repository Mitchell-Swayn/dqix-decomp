#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02161264; symbol: func_ov000_02161264; size: 0x10.
extern "C" unsigned int func_ov000_02161264(void *p) {
    return *(unsigned int *)((unsigned char *)p + 0x55f4) & 0x400;
}
