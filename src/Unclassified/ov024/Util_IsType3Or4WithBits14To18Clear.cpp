#include <globaldefs.h>
ARM
// Original: arm9/ov024 @ 0x021EA4D0; symbol: func_ov024_021ea4d0; size: 0x30.
extern "C" int Util_IsType3Or4WithBits14To18Clear(int unused, void *object) {
    unsigned int type = *(unsigned int *)((char *)object + 0x14) >> 28;
    if (type != 4 && type != 3)
        goto invalid;
    if (((*(unsigned int *)((char *)object + 0x1c) << 13) >> 27) == 0)
        return 1;
invalid:
    return 0;
}
