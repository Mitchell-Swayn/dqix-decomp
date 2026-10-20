#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB498; symbol: func_ov023_021fb498; size: 0x44.
extern "C" void Math_ConvertFixedPointPairToHalfwords(void *output, const int *values) {
    *(unsigned short *)((unsigned char *)output + 0x28) = (unsigned short)((float)values[0] / 4096.0f);
    *(unsigned short *)((unsigned char *)output + 0x2A) = (unsigned short)((float)values[1] / 4096.0f);
}
