#pragma optimize_for_size off

extern "C" double func_020054f4(const char*, char**);

// Decimal floating-point conversion without an end-pointer result.
extern "C" double func_020055d4(const char* text)
{
    return func_020054f4(text, 0);
}
