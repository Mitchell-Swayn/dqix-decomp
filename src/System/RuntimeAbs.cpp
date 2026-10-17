#pragma optimize_for_size off

// Original: arm9/main @ 0x020017A4; symbol: abs; size: 0xC.
extern "C" int abs(int value)
{
    return value < 0 ? -value : value;
}

// Original: arm9/main @ 0x020017B0; symbol: labs; size: 0xC.
extern "C" long labs(long value)
{
    return value < 0 ? -value : value;
}
