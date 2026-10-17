#pragma optimize_for_size off
#include <globaldefs.h>

extern "C" unsigned int data_0210f3c0[];
extern "C" void SubmitOperationCodeTwentySix(unsigned int mask, int enabled);

// Original: arm9/main @ 0x020BBE1C; symbol: func_020bbe1c; size: 0x48.
extern "C" int ReservePreviouslyUnusedMaskBits(unsigned int mask)
{
    if (mask == 0) {
        return 1;
    }
    if ((mask & data_0210f3c0[2]) != 0) {
        return 0;
    }
    SubmitOperationCodeTwentySix(mask, 0);
    data_0210f3c0[2] |= mask;
    return 1;
}
