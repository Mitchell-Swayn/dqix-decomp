#include <globaldefs.h>
// func_020e544c: 0x020e544c–0x020e545c, arm; 16 bytes
// Original: arm9/main @ 0x020E544C; symbol: func_020e544c; size: 0x10.
extern "C" unsigned int ExtractLowTwelveBitsAndShiftByFour(const int* value) {
    return ((unsigned int)*value << 20) >> 16;
}
