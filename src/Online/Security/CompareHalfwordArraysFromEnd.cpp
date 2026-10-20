#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0220BDCC; symbol: func_ov031_0220bdcc; size: 0x38.
extern "C" int CompareHalfwordArraysFromEnd(const unsigned short *left, const unsigned short *right, int count) {
    int index = count - 1;
    if (index >= 0) {
        do {
            unsigned short b = right[index];
            unsigned short a = left[index];
            if (a > b) return 1;
            if (a < b) return -1;
        } while (--index >= 0);
    }
    return 0;
}
