#include <globaldefs.h>
ARM
extern "C" unsigned int AlignAddressToWord(unsigned int);
// Original: arm9/ov031 @ 0x022054FC; symbol: func_ov031_022054fc; size: 0x28.
extern "C" unsigned int Math_SumAlignedHeaderFields(const void *p) {
    unsigned int second = AlignAddressToWord(*(const unsigned char *)((const char *)p + 3) << 2);
    unsigned int first = AlignAddressToWord(*(const unsigned short *)p);
    return second + first;
}
