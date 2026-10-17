#include <globaldefs.h>
ARM
// Original: arm9/ov027 @ 0x021D9DD8; symbol: func_ov027_021d9dd8; size: 0x10.
extern "C" unsigned Math_MaxUnsigned(unsigned a, unsigned b) {
    if (b <= a) b = a;
    return b;
}
