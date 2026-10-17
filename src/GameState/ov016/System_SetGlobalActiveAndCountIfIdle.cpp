#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov016_0219d0c0[];
// Original: arm9/ov016 @ 0x0218C024; symbol: func_ov016_0218c024; size: 0x28.
extern "C" void System_SetGlobalActiveAndCountIfIdle(void) {
    data_ov016_0219d0c0[1] = 1;
    if (data_ov016_0219d0c0[14] == 0)
        data_ov016_0219d0c0[15] += 1;
}
