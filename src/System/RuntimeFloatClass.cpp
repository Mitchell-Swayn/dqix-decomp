#pragma optimize_for_size off

// Inspect the binary64 words in the pinned little-endian ARM runtime ABI.
extern "C" int func_0200aa60(double value)
{
    return ((unsigned int*)&value)[1] & 0x80000000;
}
extern "C" int func_0200aa74(double value)
{
    unsigned int high = ((unsigned int*)&value)[1];
    unsigned int exponent = high & 0x7ff00000;
    if (exponent) {
        if (exponent == 0x7ff00000)
            return (high & 0x000fffff) || ((unsigned int*)&value)[0] ? 1 : 2;
    } else {
        return (high & 0x000fffff) || ((unsigned int*)&value)[0] ? 5 : 3;
    }
    return 4;
}
