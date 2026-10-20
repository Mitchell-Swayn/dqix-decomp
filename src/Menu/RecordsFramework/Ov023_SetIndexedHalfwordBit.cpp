#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F6E10; symbol: func_ov023_021f6e10; size: 0x24.
extern "C" void Ov023_SetIndexedHalfwordBit(void *object, unsigned int index, unsigned int bit) {
    if (bit >= 0x10)
        return;
    unsigned short *value = (unsigned short *)((char *)object + 0x2c + index * 2);
    *value = *value | (1 << (int)bit);
}
