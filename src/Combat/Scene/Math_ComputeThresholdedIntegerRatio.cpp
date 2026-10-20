#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02167B5C; symbol: func_ov000_02167b5c; size: 0x58.
extern "C" int Math_ComputeThresholdedIntegerRatio(int base, int index) {
    int n = index - 1;
    int low = n * 0x199 + 0x4000;
    int high = n * 0xb33 + base;
    int result = 0xb33;
    if (high < low) goto done;
    if (low < base) {
        result = 0x199;
        goto done;
    }
    if ((unsigned)index > 1) result = (low - base) / n;
done:
    return result;
}
