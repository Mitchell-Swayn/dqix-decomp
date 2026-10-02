// Helpers used by ov009's text-pattern evaluation at 02189a4c.
// The first argument is the surrounding text context; these operations do not
// read it. Keep the original interfaces used by the remaining fallback caller.
extern "C" int func_02001aec(const void*, const void*, unsigned int);

extern "C" void func_ov009_0218a484(void*, const char* source, char* destination)
{
    // Callers clear their temporary buffer first; this does not copy the NUL.
    // Branch-local assignment expressions preserve MWCC's signed-byte reloads.
    while (*source != 0) {
        if (((*source >= 'a' && *source <= 'z')
                ? (*destination = *source - ('a' - 'A'))
                : (*destination = *source)) != 0)
            ++source;
        ++destination;
    }
}

extern "C" bool func_ov009_0218a4c8(void*, const char* pattern,
                                   const char* text, int length, int positions)
{
    for (int i = 0; i < positions; ++i, ++text) {
        if (func_02001aec(pattern, text, length) == 0)
            return true;
    }
    return false;
}
