#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov016_0219d144[];

// Original: arm9/ov016 @ 0x0218D294; symbol: func_ov016_0218d294; size: 0x28.
extern "C" void Resource_SetGlobalFlagAndAdvanceCounterIfReady(void) {
    data_ov016_0219d144[0] = 1;
    if (data_ov016_0219d144[5] == 0)
        data_ov016_0219d144[6] += 1;
}
