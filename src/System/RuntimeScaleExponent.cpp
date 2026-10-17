#pragma optimize_for_size off

// Binary64 word access follows the pinned little-endian ARM runtime ABI.
extern "C" int Runtime_ClassifyDouble(double);
extern "C" double Runtime_CopyDoubleSign(double, double);
// Original: arm9/main @ 0x020091D8; symbol: func_020091d8; size: 0x24C.
extern "C" double Runtime_ScaleDoubleExponent(double value, int shift)
{
    if (Runtime_ClassifyDouble(value) <= 2 || 0.0 == value)
        return value;
    int high = ((int*)&value)[1];
    int low = ((int*)&value)[0];
    int exponent = (high & 0x7ff00000) >> 20;
    if (exponent == 0) {
        if ((low | (high & 0x7fffffff)) == 0)
            return value;
        value *= 18014398509481984.0;
        high = ((int*)&value)[1];
        exponent = ((high & 0x7ff00000) >> 20) - 54;
        if (shift < -50000)
            return 1.0e-300 * value;
    }
    if (exponent == 0x7ff)
        return value + value;
    exponent += shift;
    if (exponent > 0x7fe)
        return 1.0e300 * Runtime_CopyDoubleSign(1.0e300, value);
    if (exponent > 0) {
        ((int*)&value)[1] = (high & 0x800fffff) | (exponent << 20);
        return value;
    }
    if (exponent <= -54) {
        if (shift > 50000)
            return 1.0e300 * Runtime_CopyDoubleSign(1.0e300, value);
        return 1.0e-300 * Runtime_CopyDoubleSign(1.0e-300, value);
    }
    exponent += 54;
    ((int*)&value)[1] = (high & 0x800fffff) | (exponent << 20);
    return 5.55111512312578270212e-17 * value;
}
