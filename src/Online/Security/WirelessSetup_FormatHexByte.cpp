#pragma thumb on
#pragma optimize_for_size off
#pragma optimization_level 4
// Original: arm9/ov031 @ 0x022228C0; symbol: func_ov031_022228c0; size: 0x34.
// Formats the low byte as two uppercase hexadecimal digits and a terminator.
extern "C" int WirelessSetup_FormatHexByte(char* output, int value)
{
    char* cursor = output;
    unsigned char byte = value;
    int i;
    int nibble = (byte & 0xf0) >> 4;
    i = 0;
    int low = byte & 0xf;
    for (; i < 2; ++i) {
        if (nibble <= 9) nibble += '0';
        else nibble += 'A' - 10;
        *cursor++ = nibble;
        nibble = low;
    }
    *cursor = 0;
    return cursor - output;
}
