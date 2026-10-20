#include <globaldefs.h>
#include <System/Memory.h>
ARM
#pragma force_active on
#pragma optimization_level 4
extern "C" int Math_GetSignificantHalfwordCount(unsigned short*, int);
// Original: arm9/ov031 @ 0x0220BCBC; symbol: func_ov031_0220bcbc; size: 0xA8.
// Subtracts little-endian halfword integers with signed borrow propagation.
extern "C" void Math_SubtractHalfwordIntegers(unsigned short* output, unsigned short* left, unsigned short* right, int capacity)
{
    int significant = Math_GetSignificantHalfwordCount(left, capacity);
    int rightSize = Math_GetSignificantHalfwordCount(right, capacity);
    if (significant < rightSize) significant = rightSize;
    if (significant != capacity) ++significant;
    int i;
    int borrow = 0;
    for (i = 0; i < significant || (i < capacity && borrow != 0); ++i) {
        int value = left[i] - right[i] + borrow;
        output[i] = value;
        borrow = value >> 16;
    }
    if (output == left || output == right) return;
    VectorizedMemset(output + i, 0, (capacity - i) * 2);
}
