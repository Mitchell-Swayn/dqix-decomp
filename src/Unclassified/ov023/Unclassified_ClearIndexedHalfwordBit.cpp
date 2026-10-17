#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F6E34; symbol: func_ov023_021f6e34; size: 0x28.
extern "C" unsigned int Unclassified_ClearIndexedHalfwordBit(void *object, unsigned int index, unsigned int bit) {
    if (bit >= 0x10)
        return (unsigned int)object;
    unsigned short *entry = (unsigned short *)((unsigned char *)object + 0x2c) + index;
    unsigned int value = *entry & ~(1u << bit);
    *entry = (unsigned short)value;
    return value;
}
