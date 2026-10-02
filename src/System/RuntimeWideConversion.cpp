#pragma optimize_for_size off
#pragma dont_inline on
struct RuntimeCharacterMethods {
    int (*decode)(unsigned short*, const char*, unsigned int);
    int (*encode)(char*, unsigned short);
};
struct RuntimeLocale {
    unsigned int unknown[2];
    RuntimeCharacterMethods* characters;
};
extern RuntimeLocale data_020eed28;
extern "C" char* strncpy(char*, const char*, unsigned int);
extern "C" int func_020019ac(char* dest, unsigned short value)
{
    return data_020eed28.characters->encode(dest, value);
}
extern "C" unsigned int func_020019c8(char* dest, const unsigned short* source, unsigned int count)
{
    unsigned int written = 0;
    char temporary[4];
    if (!dest || !source)
        return 0;
    do {
        unsigned short value = *source;
        if (!value) {
            dest[written] = 0;
            break;
        }
        ++source;
        unsigned int length = func_020019ac(temporary, value);
        if (written + length > count)
            break;
        strncpy(dest + written, temporary, length);
        written += length;
    } while (written <= count);
    return written;
}
