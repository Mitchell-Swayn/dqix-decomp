#include <globaldefs.h>
ARM
// Original: arm9/ov024 @ 0x021F7158; symbol: func_ov024_021f7158; size: 0x50.
extern "C" bool Math_ScaleCoordinatePairWhenFieldEqualsTen(void *record) {
    void *object = *(void **)((unsigned char *)record + 8);
    if (object != 0 && ((((unsigned int)*(unsigned short *)((unsigned char *)object + 0x0A) << 21) >> 28) == 10)) {
        *(float *)((unsigned char *)record + 0x1C) = *(float *)((unsigned char *)record + 0x14) * 1.5f;
        *(float *)((unsigned char *)record + 0x20) = *(float *)((unsigned char *)record + 0x18) * 1.5f;
    }
    return true;
}
