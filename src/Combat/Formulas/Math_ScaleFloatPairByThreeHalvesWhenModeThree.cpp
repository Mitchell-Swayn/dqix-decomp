#include <globaldefs.h>
ARM
// Original: arm9/ov024 @ 0x021F6C70; symbol: func_ov024_021f6c70; size: 0x50.
extern "C" int Math_ScaleFloatPairByThreeHalvesWhenModeThree(unsigned char *self) {
    unsigned char *record = *(unsigned char **)(self + 8);
    if (record != 0 && (((unsigned int)*(unsigned short *)(record + 0x0A) << 21) >> 28) == 3) {
        *(float *)(self + 0x1C) = *(float *)(self + 0x14) * 1.5f;
        *(float *)(self + 0x20) = *(float *)(self + 0x18) * 1.5f;
    }
    return 1;
}
