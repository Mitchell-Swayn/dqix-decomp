#pragma thumb off
// Complements the low 16 bits, returning 0xFFFF when that complement is zero.
// Original: arm9/ov031 @ 0x02200668; symbol: func_ov031_02200668; size: 0x1C.
extern "C" unsigned int Network_ComplementChecksumWithNonzeroEncoding(unsigned int value)
{
    unsigned int result = (value ^ 0xFFFF) & 0xFFFF;
    if (result == 0)
        result = 0xFFFF;
    return result;
}
