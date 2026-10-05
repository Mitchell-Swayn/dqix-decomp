#pragma optimize_for_size off

// Binary64 word access follows the pinned little-endian ARM runtime ABI.
extern "C" double func_0200911c(double value, int* exponent)
{
    int high = ((int*)&value)[1];
    int low = ((int*)&value)[0];
    int magnitude = high & 0x7fffffff;
    *exponent = 0;
    if (magnitude >= 0x7ff00000 || (magnitude | low) == 0)
        return value;
    if (magnitude < 0x00100000) {
        value *= 18014398509481984.0;
        high = ((int*)&value)[1];
        *exponent = -54;
        magnitude = high & 0x7fffffff;
    }
    *exponent += (magnitude >> 20) - 1022;
    ((int*)&value)[1] = (high & 0x800fffff) | 0x3fe00000;
    return value;
}
