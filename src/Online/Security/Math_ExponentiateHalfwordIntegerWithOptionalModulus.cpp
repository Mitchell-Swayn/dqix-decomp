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
// Original data: arm9/ov031 @ 0x0224C994; symbol: data_ov031_0224c994.
// Zero-initialized allocator callback slot; assigned at runtime. Values: docs/data-symbols/ov031.md.
extern "C" void* (*SslSendClientHello_UnknownRoleZeroInitializedStorage)(unsigned);
// Original data: arm9/ov031 @ 0x0224C9C0; symbol: data_ov031_0224c9c0.
// Zero-initialized release callback slot; assigned at runtime. Values: docs/data-symbols/ov031.md.
extern "C" void (*SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2)(void*);
// Original: arm9/ov031 @ 0x0220C2BC; symbol: func_ov031_0220c2bc; size: 0x194.
// Performs left-to-right binary exponentiation, optionally reducing after each square and multiply.
extern "C" void Math_ExponentiateHalfwordIntegerWithOptionalModulus(unsigned short* output, unsigned short* base, unsigned short* exponent, int count, unsigned short* modulus)
{
    unsigned short* temporary = (unsigned short*)SslSendClientHello_UnknownRoleZeroInitializedStorage(count * 8);
    if (!temporary) return;
    unsigned short* divisionScratch = temporary + count;
    VectorizedMemset(output + 1, 0, (count - 1) * 2);
    output[0] = 1;
    unsigned bit = (count - Math_GetSignificantHalfwordCount(exponent, count)) * 16;
    if (bit < (unsigned)(count * 16)) do {
        if (exponent[count - ((int)bit >> 4) - 1] & (0x8000u >> (bit & 15))) {
            MI_CpuCopy8(base, output, count * 2);
            ++bit;
            break;
        }
        ++bit;
    } while (bit < (unsigned)(count * 16));
    if (bit < (unsigned)(count * 16)) do {
        Math_SquareHalfwordInteger(temporary, output, count);
        MI_CpuCopy8(temporary, output, count * 2);
        if (modulus) Math_DivideHalfwordIntegers(0, output, modulus, output, count, divisionScratch);
        if (exponent[count - ((int)bit >> 4) - 1] & (0x8000u >> (bit & 15))) {
            Math_MultiplyHalfwordArraysTruncated(temporary, output, base, count);
            MI_CpuCopy8(temporary, output, count * 2);
            if (modulus) Math_DivideHalfwordIntegers(0, output, modulus, output, count, divisionScratch);
        }
        ++bit;
    } while (bit < (unsigned)(count * 16));
    SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2(temporary);
}
