#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov016_0219d0c0[];

// Original: arm9/ov016 @ 0x0218BE5C; symbol: func_ov016_0218be5c; size: 0x20.
extern "C" unsigned int Graphics_GetVramAddressForModeFlag(void) {
    if (data_ov016_0219d0c0[6] == 0)
        return 0x06820000;
    return 0x06800000;
}
