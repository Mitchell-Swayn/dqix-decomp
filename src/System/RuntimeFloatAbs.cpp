#pragma optimize_for_size off

// Inspect the binary64 words in the pinned little-endian ARM runtime ABI.
extern "C" double func_02008f3c(double value)
{
    unsigned int* words = (unsigned int*)&value;
    words[1] &= 0x7fffffff;
    return value;
}
