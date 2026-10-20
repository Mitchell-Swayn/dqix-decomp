#pragma optimize_for_size off
extern "C" double RuntimeFrexp_DecomposeDoubleExponent(double, int*);
extern "C" double Runtime_ScaleDoubleExponent(double, int);
// Original: arm9/main @ 0x0200AAE4; symbol: func_0200aae4; size: 0x2C.
extern "C" double Runtime_ScaleNormalizedDoubleByPowerOfTwo(double value, int shift)
{
    int exponent;
    value = RuntimeFrexp_DecomposeDoubleExponent(value, &exponent);
    exponent += shift;
    return Runtime_ScaleDoubleExponent(value, exponent);
}
