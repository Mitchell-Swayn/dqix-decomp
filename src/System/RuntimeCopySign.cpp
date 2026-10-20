#pragma optimize_for_size off

// Inspect the binary64 words in the pinned little-endian ARM runtime ABI.
// Original: arm9/main @ 0x02008DA4; symbol: func_02008da4; size: 0x28.
extern "C" double Runtime_CopyDoubleSign(double value, double sign)
{
    ((unsigned int*)&value)[1] = (((unsigned int*)&value)[1] & 0x7fffffff) |
                                (((unsigned int*)&sign)[1] & 0x80000000);
    return value;
}
