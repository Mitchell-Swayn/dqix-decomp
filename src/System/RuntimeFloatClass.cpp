#pragma optimize_for_size off

// Inspect the binary64 words in the pinned little-endian ARM runtime ABI.
// Original: arm9/main @ 0x0200AA60; symbol: func_0200aa60; size: 0x14.
extern "C" int RuntimeFloatClass_ReadDoubleSignBit(double value)
{
    return ((unsigned int*)&value)[1] & 0x80000000;
}
// Original: arm9/main @ 0x0200AA74; symbol: func_0200aa74; size: 0x70.
extern "C" int Runtime_ClassifyDouble(double value)
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
