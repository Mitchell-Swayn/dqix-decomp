#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02218798; symbol: func_ov031_02218798; size: 0xC.
extern "C" unsigned int ClearBitFifteenFromUnsignedValue(unsigned int arg0) {
    if (arg0 & 0x8000) {
        arg0 &= ~0x8000;
    }
    return arg0;
}
