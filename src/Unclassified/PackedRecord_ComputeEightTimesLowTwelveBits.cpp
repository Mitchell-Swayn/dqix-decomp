#include <globaldefs.h>
// func_02079ce8: 0x02079ce8–0x02079cf8, arm; 16 bytes
// Original: arm9/main @ 0x02079CE8; symbol: func_02079ce8; size: 0x10.
extern "C" unsigned int PackedRecord_ComputeEightTimesLowTwelveBits(const int* value) {
    return ((unsigned int)*value << 20) >> 17;
}
