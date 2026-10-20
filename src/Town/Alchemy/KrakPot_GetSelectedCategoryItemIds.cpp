#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x0215919C; symbol: Unclassified_GetIndexedWordFromField362Offset; size: 0x28.
// Subtracts 0x5B from the signed halfword at +0x362; if nonnegative, returns the indexed word from the pointer at +0x48, otherwise zero.
extern "C" unsigned int KrakPot_GetSelectedCategoryItemIds(unsigned char *p) {
    int index = (signed short)(*(signed short *)(p + 0x362) - 0x5b);
    unsigned int result = 0;
    if (index >= 0) result = *(unsigned int *)(*(unsigned int **)(p + 0x48) + index);
    return result;
}
