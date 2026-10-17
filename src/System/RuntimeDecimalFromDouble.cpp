#include "System/RuntimeDecimal.h"
#pragma optimize_for_size off
extern "C" int RuntimeFloatClass_ReadDoubleSignBit(double);
extern "C" int Runtime_ClassifyDouble(double);
extern "C" double RuntimeFrexp_DecomposeDoubleExponent(double, int*);
extern "C" double Runtime_ScaleDoubleExponent(double, int);
extern "C" int Runtime_CountSetBits64(unsigned long long);
extern "C" void RuntimeDecimalPowerOfTwo_ComputeDecimalPowerOfTwo(RuntimeDecimal*, int);
extern "C" void Runtime_ConvertUnsignedToDecimalDigits(RuntimeDecimal*, unsigned long long);
extern "C" void func_02009778(RuntimeDecimal*, const RuntimeDecimal*, const RuntimeDecimal*);
// Original: arm9/main @ 0x0200A180; symbol: func_0200a180; size: 0x180.
extern "C" void RuntimeDecimalFromDouble_ConvertDoubleToDecimal(RuntimeDecimal* result, double value)
{
    char negative = RuntimeFloatClass_ReadDoubleSignBit(value) != 0;
    if (0.0 == value) {
        result->sign = negative;
        result->exponent = 0;
        result->length = 1;
        result->digits[0] = 0;
        return;
    }
    if (Runtime_ClassifyDouble(value) <= 2) {
        result->sign = negative;
        result->exponent = 0;
        result->length = 1;
        result->digits[0] = Runtime_ClassifyDouble(value) == 1 ? 'N' : 'I';
        return;
    }
    if (negative)
        value = -value;
    int exponent;
    union { double floating; unsigned long long bits; } fraction;
    value = RuntimeFrexp_DecomposeDoubleExponent(value, &exponent);
    fraction.floating = value;
    unsigned long long bits = fraction.bits | (1ULL << 52);
    int precision = 53 - Runtime_CountSetBits64((bits & -bits) - 1);
    RuntimeDecimal integer, power;
    RuntimeDecimalPowerOfTwo_ComputeDecimalPowerOfTwo(&power, exponent - precision);
    Runtime_ConvertUnsignedToDecimalDigits(&integer, (unsigned long long)Runtime_ScaleDoubleExponent(value, precision));
    func_02009778(result, &integer, &power);
    result->sign = negative;
}
