#pragma optimize_for_size off

// Inspect the binary64 words in the pinned little-endian ARM runtime ABI.
extern "C" double func_02008da4(double value, double sign)
{
    ((unsigned int*)&value)[1] = (((unsigned int*)&value)[1] & 0x7fffffff) |
                                (((unsigned int*)&sign)[1] & 0x80000000);
    return value;
}
