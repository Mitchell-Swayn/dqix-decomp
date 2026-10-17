#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x021598A4; symbol: func_ov000_021598a4; size: 0x18.
extern "C" int func_ov000_021598a4(void *p) {
    unsigned int value = *(unsigned int *)(*(unsigned char **)((unsigned char *)p + 0x138) + 0x14);
    return (value & 0x20000000) != 0;
}
