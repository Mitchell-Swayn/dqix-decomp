#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x021591C4; symbol: GetPointerBySignedRecordIndex; size: 0x28.
// Subtracts 0x5B from signed halfword field +0x362 and returns that index from the pointer table at +0x4C when nonnegative.
extern "C" unsigned int KrakPot_GetSelectedCategoryItemQuantities(unsigned char *p) {
    int index = (signed short)(*(signed short *)(p + 0x362) - 0x5b);
    unsigned int result = 0;
    if (index >= 0) result = *(unsigned int *)(*(unsigned int **)(p + 0x4c) + index);
    return result;
}
