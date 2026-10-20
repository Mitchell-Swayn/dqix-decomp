#include <globaldefs.h>
ARM
#include <System/Memory.h>
extern "C" int Math_GetSignificantHalfwordCount(const unsigned short *, int);
// Original: arm9/ov031 @ 0x0220BB7C; symbol: func_ov031_0220bb7c; size: 0x9C.
extern "C" void Math_AddHalfwordArrays(unsigned short *out, const unsigned short *a, const unsigned short *b, int capacity) {
    int count = Math_GetSignificantHalfwordCount(a, capacity);
    int bCount = Math_GetSignificantHalfwordCount(b, capacity);
    if (count < bCount) count = bCount;
    if (count != capacity) ++count;
    int i;
    unsigned carry = 0;
    i = 0;
    for (; i < count; ++i) {
        unsigned sum = carry + (a[i] + b[i]);
        out[i] = sum;
        carry = sum >> 16;
    }
    if (out == a || out == b) return;
    VectorizedMemset(out + i, 0, (capacity - i) * 2);
}
