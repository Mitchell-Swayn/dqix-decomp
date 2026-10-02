#pragma optimize_for_size off

extern "C" int func_020059cc(const char*, char**, int);

// Decimal integer conversion without an end-pointer result.
extern "C" int func_02005a94(const char* text)
{
    return func_020059cc(text, 0, 10);
}

// This runtime uses two-byte wide characters.
extern "C" unsigned int func_02005aa8(const unsigned short* text)
{
    unsigned int length = -1;
    do {
        ++length;
    } while (*text++);
    return length;
}
