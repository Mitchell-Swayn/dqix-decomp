#pragma thumb on
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" int WirelessSetup_FormatHexByte(char*, int);
// Original: arm9/ov031 @ 0x022228F4; symbol: func_ov031_022228f4; size: 0x34.
// Formats six address bytes as uppercase hexadecimal pairs separated by colons.
extern "C" int WirelessSetup_FormatMacAddress(char* output, const signed char* address)
{
    char* cursor = output;
    for (int i = 0; i < 6; ++i) {
        cursor += WirelessSetup_FormatHexByte(cursor, *address++);
        if (i < 5) *cursor++ = ':';
    }
    *cursor = 0;
    return cursor - output;
}
