#pragma optimize_for_size off

// Binary64 word access follows the pinned little-endian ARM runtime ABI.
extern "C" int func_0200aa74(double);
extern "C" double func_02008da4(double, double);
extern "C" double func_020091d8(double value, int shift)
{
    if (func_0200aa74(value) <= 2 || 0.0 == value)
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
        return 1.0e300 * func_02008da4(1.0e300, value);
    if (exponent > 0) {
        ((int*)&value)[1] = (high & 0x800fffff) | (exponent << 20);
        return value;
    }
    if (exponent <= -54) {
        if (shift > 50000)
            return 1.0e300 * func_02008da4(1.0e300, value);
        return 1.0e-300 * func_02008da4(1.0e-300, value);
    }
    exponent += 54;
    ((int*)&value)[1] = (high & 0x800fffff) | (exponent << 20);
    return 5.55111512312578270212e-17 * value;
}
