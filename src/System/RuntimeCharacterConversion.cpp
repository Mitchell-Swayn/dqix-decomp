#pragma optimize_for_size off

// This runtime converts one unsigned byte to/from its two-byte character type.
extern "C" {

int func_02001960(unsigned short* wide, const char* text, unsigned int count)
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

int func_02001998(char* dest, unsigned short value)
{
    if (!dest)
        return 0;
    *dest = value;
    return 1;
}
}
