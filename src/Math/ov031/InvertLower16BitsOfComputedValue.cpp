#include <globaldefs.h>
ARM
extern "C" unsigned int Network_AccumulateBigEndianChecksum(int, int, int);
extern "C" unsigned short InvertLower16Bits(unsigned short);
// Original: arm9/ov031 @ 0x02200684; symbol: func_ov031_02200684; size: 0x1C.
extern "C" unsigned short InvertLower16BitsOfComputedValue(int first, int second) {
    unsigned short value = (unsigned short)Network_AccumulateBigEndianChecksum(first, second, 0);
    return InvertLower16Bits(value);
}
