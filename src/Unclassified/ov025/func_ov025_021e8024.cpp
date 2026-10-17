#include <globaldefs.h>
ARM
extern "C" ARM void UpdateByteLevelTransitionAndThreeChannels(unsigned char *, unsigned char, int);
extern "C" unsigned char data_02109bf4[];
// Original: arm9/ov025 @ 0x021E8024; symbol: func_ov025_021e8024; size: 0x20.
extern "C" int func_ov025_021e8024(unsigned char *p) {
    UpdateByteLevelTransitionAndThreeChannels(data_02109bf4, p[8], *(unsigned short *)(p + 0xa));
    return 1;
}
