// Membership check used for bracketed byte sets in 0218a518's pattern matcher.
extern "C" bool func_ov009_0218a888(void*, const unsigned char* set,
                                   int length, int value)
{
    for (int i = 0; i < length; ++i, ++set) {
        if (*set == value)
            return true;
    }
    return false;
}
