#include <globaldefs.h>
extern "C" int RuntimeMemory_CompareByteRanges(const void*, const void*, unsigned int);
// Search the candidate byte sequence at each of count consecutive offsets.
// Original: arm9/ov012 @ 0x02185634; symbol: func_ov012_02185634; size: 0x50.
extern "C" int ProfileTextFilter_ContainsByteSequence(void*, const void* candidate, const unsigned char* bytes, unsigned int length, int count)
{
    for (int i = 0; i < count; ++i, ++bytes)
        if (RuntimeMemory_CompareByteRanges(candidate, bytes, length) == 0) return 1;
    return 0;
}
