#include <globaldefs.h>
ARM

extern "C" int FastIntDivide(int a, int b);
extern "C" unsigned char data_ov031_02290ca0[];

// Original: arm9/ov031 @ 0x022305A4; symbol: func_ov031_022305a4; size: 0x44.
extern "C" int Unclassified_FindOffsetWithinFourValues(int value) {
    int quotient = FastIntDivide(*(unsigned short *)(data_ov031_02290ca0 + 4), 0x1d);
    int index = 0;
    do {
        if (quotient == value) {
            return index;
        }
        index++;
        quotient++;
    } while (index < 4);
    return -1;
}
