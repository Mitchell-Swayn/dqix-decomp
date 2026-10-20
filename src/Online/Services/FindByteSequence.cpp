#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original: arm9/ov031 @ 0x02242F84; symbol: func_ov031_02242f84; size: 0x84.
extern "C" int FindByteSequence(const char *buffer, int length, const char *pattern, int patternLength) {
    if (length < patternLength) return -1;
    int i;
    int j;
    const char *candidate;
    char first;
    int count = length - patternLength + 1;
    i = 0;
    if (count > 0) {
    first = pattern[0];
    do {
        if (first == buffer[i]) {
            j = 1;
            candidate = buffer + i;
            for (; j < patternLength; ++j) {
                if (candidate[j] != pattern[j]) break;
            }
            if (j == patternLength) return 0;
        }
        ++i;
    } while (i < count);
    }
    return -1;
}
