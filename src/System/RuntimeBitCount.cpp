#pragma optimize_for_size off
// Count significand bits with the original parallel 64-bit mask reductions.
extern "C" int func_0200a9cc(unsigned long long value)
{
    value -= (value >> 1) & 0x5555555555555555ULL;
    value = (value & 0x3333333333333333ULL) + ((value >> 2) & 0x3333333333333333ULL);
    value = (value + (value >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
    value += value >> 8;
    value += value >> 16;
    value += value >> 32;
    return value & 0xff;
}
