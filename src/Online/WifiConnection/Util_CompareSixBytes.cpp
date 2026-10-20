#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0220F368; symbol: func_ov031_0220f368; size: 0x2C.
extern "C" int Util_CompareSixBytes(const unsigned char *a, const unsigned char *b) {
    int i = 0;
    do {
        if (a[i] != b[i])
            return 0;
        ++i;
    } while (i < 6);
    return 1;
}
