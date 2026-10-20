#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original: arm9/main @ 0x020D3044; symbol: func_020d3044; size: 0x40.
extern "C" int Memory_CompareUnsignedBytesForCount(const unsigned char *left, const unsigned char *right, int count) {
    if (count != 0) {
        int i = 0;
        if (count > 0) {
            do {
                unsigned int a = left[i];
                unsigned int b = right[i];
                if (a != b)
                    return a - b;
                ++i;
            } while (i < count);
        }
    }
    return 0;
}
