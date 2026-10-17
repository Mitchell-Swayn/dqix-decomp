#include <globaldefs.h>
THUMB
extern "C" long long _ll_mul(long long, long long);
extern "C" void func_ov031_0220783c(int *, int, int, int);
// Original: arm9/ov031 @ 0x0221E54C; symbol: func_ov031_0221e54c; size: 0x54.
extern "C" void Math_InitializePairWithScaledSum(void *unused0, int *values, int unused2, int unused3, int *scales) {
    int first = values[0];
    int second = values[1];
    int output[2];
    output[1] = second;
    output[0] = first;
    unsigned long long total = 0;
    total += (unsigned long long)_ll_mul(scales[0], 0x01ff6210LL) >> 6;
    total += (unsigned long long)_ll_mul(scales[1], 0x01ff6210LL) >> 6;
    func_ov031_0220783c(output, 1, (int)total, (int)(total >> 32));
}
