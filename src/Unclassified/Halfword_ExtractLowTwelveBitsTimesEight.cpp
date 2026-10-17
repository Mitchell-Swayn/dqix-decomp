#include <globaldefs.h>
// func_020dffb8: 0x020dffb8–0x020dffc8, arm; 16 bytes
// Original: arm9/main @ 0x020DFFB8; symbol: func_020dffb8; size: 0x10.
extern "C" unsigned int Halfword_ExtractLowTwelveBitsTimesEight(const int* value) {
    return ((unsigned int)*value << 20) >> 17;
}
