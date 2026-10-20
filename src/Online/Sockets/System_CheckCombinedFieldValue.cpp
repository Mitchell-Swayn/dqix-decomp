#include <globaldefs.h>
ARM

extern "C" unsigned Network_AccumulateBigEndianChecksum(void *, unsigned, unsigned);

// Original: arm9/ov031 @ 0x022006A0; symbol: func_ov031_022006a0; size: 0x50.
extern "C" int System_CheckCombinedFieldValue(void *first, unsigned offset, void *second, unsigned argument) {
    unsigned value = Network_AccumulateBigEndianChecksum(first, offset, argument);
    value = Network_AccumulateBigEndianChecksum((char *)second + 0xC, 8, value);
    unsigned result = value + offset;
    if (result & 0x10000) {
        result = (result + 1) & 0xFFFF;
    }
    return result != 0xFFFF;
}
