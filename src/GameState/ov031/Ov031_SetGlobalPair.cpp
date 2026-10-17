#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_0224e5ac[];
// Original: arm9/ov031 @ 0x02211B40; symbol: func_ov031_02211b40; size: 0x14.
extern "C" void Ov031_SetGlobalPair(unsigned int first, unsigned int second) {
    data_ov031_0224e5ac[1] = first;
    data_ov031_0224e5ac[0] = second;
}
