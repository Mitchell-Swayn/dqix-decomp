#include <globaldefs.h>
ARM
// Original: arm9/ov024 @ 0x021F6C40; symbol: func_ov024_021f6c40; size: 0x30.
extern "C" int Math_HalveFloatFields14And18To1CAnd20(void *object) {
    *(float *)((char *)object + 0x1c) = *(float *)((char *)object + 0x14) * 0.5f;
    *(float *)((char *)object + 0x20) = *(float *)((char *)object + 0x18) * 0.5f;
    return 1;
}
