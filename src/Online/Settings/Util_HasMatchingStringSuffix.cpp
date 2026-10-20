#include <globaldefs.h>
ARM
extern "C" unsigned int strlen(const char *);
extern "C" int RuntimeMemory_CompareByteRanges(const void *, const void *, unsigned int);

// Original: arm9/ov031 @ 0x0223B744; symbol: func_ov031_0223b744; size: 0x58.
extern "C" int Util_HasMatchingStringSuffix(const char *first, const char *second, unsigned int length) {
    unsigned int firstLength = strlen(first);
    unsigned int secondLength = strlen(second);
    if ((int)firstLength < (int)length || (int)secondLength < (int)length) return 0;
    return RuntimeMemory_CompareByteRanges(first + (firstLength - length),
        second + (secondLength - length), length) == 0;
}
