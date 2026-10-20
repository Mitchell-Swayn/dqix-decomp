#pragma optimize_for_size off

// This runtime converts one unsigned byte to/from its two-byte character type.
extern "C" {

// Original: arm9/main @ 0x02001960; symbol: func_02001960; size: 0x38.
int Runtime_ConvertByteToWideCharacter(unsigned short* wide, const char* text, unsigned int count)
{
    if (!text)
        return 0;
    if (!count)
        return -1;
    if (wide)
        *wide = (unsigned char)*text;
    if (!*text)
        return 0;
    return 1;
}

// Original: arm9/main @ 0x02001998; symbol: func_02001998; size: 0x14.
int Runtime_WriteSingleByteCharacter(char* dest, unsigned short value)
{
    if (!dest)
        return 0;
    *dest = value;
    return 1;
}
}
