#pragma optimize_for_size off

// Inspect the binary64 words in the pinned little-endian ARM runtime ABI.
// Original: arm9/main @ 0x02008F3C; symbol: func_02008f3c; size: 0x20.
extern "C" double Runtime_ComputeDoubleAbsoluteValue(double value)
{
    unsigned int* words = (unsigned int*)&value;
    words[1] &= 0x7fffffff;
    return value;
}
