#include <globaldefs.h>

extern "C" unsigned short* data_ov031_02290d14;
// Original: arm9/ov031 @ 0x0223911C; symbol: func_ov031_0223911c; size: 0x14.
extern "C" ARM unsigned short ReadGlobalHalfwordValue(void) {
    return *data_ov031_02290d14;
}
