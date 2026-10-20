#include "System/RuntimeLocale.h"

#pragma optimize_for_size off
#pragma dont_inline on
extern "C" char* strncpy(char*, const char*, unsigned int);
// Original: arm9/main @ 0x020019AC; symbol: func_020019ac; size: 0x1C.
extern "C" int RuntimeWideConversion_EncodeWideCharacter(char* dest, unsigned short value)
{
    return RuntimeWideConversionEncodeWideCharacter_UnknownRoleDataReferences.characters->encode(dest, value);
}
// Original: arm9/main @ 0x020019C8; symbol: func_020019c8; size: 0x78.
extern "C" unsigned int Runtime_ConvertWideStringToBytes(char* dest, const unsigned short* source, unsigned int count)
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
        unsigned int length = RuntimeWideConversion_EncodeWideCharacter(temporary, value);
        if (written + length > count)
            break;
        strncpy(dest + written, temporary, length);
        written += length;
    } while (written <= count);
    return written;
}
