#include "System/RuntimeDecimal.h"
#pragma optimize_for_size off
extern "C" int func_0200aa60(double);
extern "C" int func_0200aa74(double);
extern "C" double func_0200911c(double, int*);
extern "C" double func_020091d8(double, int);
extern "C" int func_0200a9cc(unsigned long long);
extern "C" void func_02009998(RuntimeDecimal*, int);
extern "C" void func_020096ac(RuntimeDecimal*, unsigned long long);
extern "C" void func_02009778(RuntimeDecimal*, const RuntimeDecimal*, const RuntimeDecimal*);
extern "C" void func_0200a180(RuntimeDecimal* result, double value)
{
    char negative = func_0200aa60(value) != 0;
    if (0.0 == value) {
        result->sign = negative;
        result->exponent = 0;
        result->length = 1;
        result->digits[0] = 0;
        return;
    }
    if (func_0200aa74(value) <= 2) {
        result->sign = negative;
        result->exponent = 0;
        result->length = 1;
        result->digits[0] = func_0200aa74(value) == 1 ? 'N' : 'I';
        return;
    }
    if (negative)
        value = -value;
    int exponent;
    union { double floating; unsigned long long bits; } fraction;
    value = func_0200911c(value, &exponent);
    fraction.floating = value;
    unsigned long long bits = fraction.bits | (1ULL << 52);
    int precision = 53 - func_0200a9cc((bits & -bits) - 1);
    RuntimeDecimal integer, power;
    func_02009998(&power, exponent - precision);
    func_020096ac(&integer, (unsigned long long)func_020091d8(value, precision));
    func_02009778(result, &integer, &power);
    result->sign = negative;
}
