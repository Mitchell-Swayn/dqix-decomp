#pragma optimize_for_size off

extern "C" double Runtime_ParseStringAsDouble(const char*, char**);

// Decimal floating-point conversion without an end-pointer result.
// Original: arm9/main @ 0x020055D4; symbol: func_020055d4; size: 0x10.
extern "C" double RuntimeDecimalDouble_ParseTextAsDouble(const char* text)
{
    return Runtime_ParseStringAsDouble(text, 0);
}
