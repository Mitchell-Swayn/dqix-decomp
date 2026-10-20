#include <globaldefs.h>
#include <System/Memory.h>
ARM
#pragma force_active on
#pragma optimization_level 4
extern "C" int Math_GetSignificantHalfwordCount(unsigned short*, int);
// Original: arm9/ov031 @ 0x0220BEE4; symbol: func_ov031_0220bee4; size: 0x78.
// Multiplies a little-endian halfword integer by a scalar and zeroes unused output words.
extern "C" void Math_MultiplyHalfwordIntegerByScalar(unsigned short* output, unsigned short* input, unsigned scalar, int capacity)
{
    int significant = Math_GetSignificantHalfwordCount(input, capacity);
    unsigned carry = 0;
    int i = 0;
    if (significant > 0) do {
        unsigned value = scalar * input[i] + carry;
        output[i] = value;
        carry = value >> 16;
        ++i;
    } while (i < significant);
    if (i < capacity) output[i++] = carry;
    VectorizedMemset(output + i, 0, (capacity - i) * 2);
}
