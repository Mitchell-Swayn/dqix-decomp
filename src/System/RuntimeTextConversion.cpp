#pragma optimize_for_size off

extern "C" int Runtime_ParseSignedStringInteger(const char*, char**, int);

// Decimal integer conversion without an end-pointer result.
// Original: arm9/main @ 0x02005A94; symbol: func_02005a94; size: 0x14.
extern "C" int Runtime_ParseStringAsBaseTenInteger(const char* text)
{
    return Runtime_ParseSignedStringInteger(text, 0, 10);
}

// This runtime uses two-byte wide characters.
// Original: arm9/main @ 0x02005AA8; symbol: func_02005aa8; size: 0x1C.
extern "C" unsigned int RuntimeTextConversion_CountWideCharacters(const unsigned short* text)
{
    unsigned int length = -1;
    do {
        ++length;
    } while (*text++);
    return length;
}
