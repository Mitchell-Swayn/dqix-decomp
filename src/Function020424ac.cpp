// Return the first unescaped '>' in a zero-terminated signed-byte string.
extern "C" char* func_020424ac(const signed char* text)
{
    if (text != 0)
    {
        while (*text != 0)
        {
            if (*text == 0x3e && text[1] != 0x3e)
                return (char*)text;
            text++;
        }
    }

    return 0;
}
