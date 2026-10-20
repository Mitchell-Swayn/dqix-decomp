#include <globaldefs.h>
ARM

// Original: arm9/ov031 @ 0x0223DD60; symbol: func_ov031_0223dd60; size: 0x48.
extern "C" unsigned int Util_CopyBytesToHalfwordsAndTerminate(unsigned short *dst, const unsigned char *src, int capacity) {
    int limit = capacity - 1;
    int count = 0;
    if (limit > 0) {
        do {
            unsigned char value = src[count];
            if (value == 0) break;
            dst[count] = value;
            count++;
        } while (count < limit);
    }
    dst[count] = 0;
    return count;
}
