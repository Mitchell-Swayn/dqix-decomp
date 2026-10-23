#pragma thumb on
#pragma optimize_for_size off
#pragma optimization_level 4
// Original: arm9/ov031 @ 0x0221E404; symbol: func_ov031_0221e404; size: 0x24.
// XORs token bytes into the second half of the output buffer.
extern "C" void WirelessSetup_XorTokenSecondHalf(const signed char* token, unsigned char* output, int length)
{
    int i;
    int half = length / 2;
    i = 0;
    if (half > 0) {
        unsigned char* second = output + half;
        do {
            *second ^= token[i];
            ++i;
            ++second;
        } while (i < half);
    }
}
