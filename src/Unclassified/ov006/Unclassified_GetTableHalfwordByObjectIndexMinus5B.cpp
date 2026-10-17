#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x021591EC; symbol: func_ov006_021591ec; size: 0x2C.
extern "C" unsigned int Unclassified_GetTableHalfwordByObjectIndexMinus5B(void *object) {
    short index = (short)(*(short *)((unsigned char *)object + 0x362) - 0x5b);
    unsigned int result = 0;
    if (index >= 0) {
        unsigned short *table = *(unsigned short **)((unsigned char *)object + 0x50);
        result = table[index];
    }
    return result;
}
