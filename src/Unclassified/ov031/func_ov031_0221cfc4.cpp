#include <globaldefs.h>
THUMB
// Original: arm9/ov031 @ 0x0221CFC4; symbol: func_ov031_0221cfc4; size: 0x18.
extern "C" unsigned func_ov031_0221cfc4(unsigned a, unsigned b) {
    unsigned common = a & b;
    unsigned left = ((a & ~b) + 1) | common;
    unsigned right = (~b) | common;
    if (left < right)
        return left;
    return 1 | common;
}
