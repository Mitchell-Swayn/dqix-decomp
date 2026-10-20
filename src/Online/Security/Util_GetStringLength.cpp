#include <globaldefs.h>
THUMB
// Original: arm9/ov031 @ 0x0221E650; symbol: func_ov031_0221e650; size: 0x14.
extern "C" unsigned int Util_GetStringLength(const char *p) {
    unsigned int n = 0;
    if (p[0] != 0) {
        do { ++n; } while (p[n] != 0);
    }
    return n;
}
