#pragma optimize_for_size off
#include <globaldefs.h>
#include <System/Memory.h>
ARM
#pragma optimization_level 4
#pragma force_active on
extern "C" int Math_GetSignificantHalfwordCount(unsigned short*, int);
extern "C" void Math_MultiplyHalfwordArraysTruncated(unsigned short*, const unsigned short*, const unsigned short*, int);
extern "C" void Math_SquareHalfwordInteger(unsigned short*, const unsigned short*, int);
extern "C" void Math_DivideHalfwordIntegers(unsigned short*, unsigned short*, unsigned short*, unsigned short*, int, unsigned short*);
extern "C" int Util_RejectHighBitLastHalfwordOrCheckTrimmedLength(const unsigned short*, int);
extern "C" void Math_SubtractHalfwordIntegers(unsigned short*, unsigned short*, unsigned short*, int);
extern "C" void Math_AddHalfwordArrays(unsigned short*, const unsigned short*, const unsigned short*, int);
// Original: arm9/ov031 @ 0x0220C450; symbol: func_ov031_0220c450; size: 0x14C.
// Uses extended Euclidean updates in caller-provided scratch arrays, then reduces the inverse modulo the supplied integer.
extern "C" void Math_InvertHalfwordIntegerModulo(unsigned short* output, unsigned short* value, unsigned short* modulus, int count, unsigned short* scratch)
{
    unsigned short* divisionScratch;
    register unsigned short* quotient = scratch + count;
    unsigned short* remainder = quotient + count;
    unsigned short* coefficient = remainder + count;
    unsigned short* previous = coefficient + count;
    unsigned short* temporary = previous + count;
    divisionScratch = temporary + count;
    unsigned bytes = count * 2;
    MI_CpuCopy8(value, scratch, bytes);
    MI_CpuCopy8(modulus, remainder, bytes);
    coefficient[0] = 1;
    if (Util_RejectHighBitLastHalfwordOrCheckTrimmedLength(scratch, count) > 0) do {
        Math_DivideHalfwordIntegers(quotient, remainder, scratch, temporary, count, divisionScratch);
        MI_CpuCopy8(scratch, remainder, bytes);
        MI_CpuCopy8(temporary, scratch, bytes);
        Math_MultiplyHalfwordArraysTruncated(temporary, quotient, coefficient, count);
        Math_SubtractHalfwordIntegers(temporary, previous, temporary, count);
        MI_CpuCopy8(coefficient, previous, bytes);
        MI_CpuCopy8(temporary, coefficient, bytes);
    } while (Util_RejectHighBitLastHalfwordOrCheckTrimmedLength(scratch, count) > 0);
    Math_AddHalfwordArrays(previous, previous, modulus, count);
    Math_DivideHalfwordIntegers(0, previous, modulus, output, count, divisionScratch);
}
