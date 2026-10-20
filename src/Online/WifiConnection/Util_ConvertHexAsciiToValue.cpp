#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02236760; symbol: func_ov031_02236760; size: 0x1C.
extern "C" unsigned int Util_ConvertHexAsciiToValue(unsigned int value) {
    if (value <= 0x39)
        return value - 0x30;
    if (value <= 0x46)
        return value - 0x37;
    return value - 0x57;
}
