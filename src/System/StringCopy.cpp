#include "std_library_functions.h"

#pragma optimize_for_size off

// Original: arm9/main @ 0x02003FF0; symbol: strncpy; size: 0x50.
char* strncpy(char* dst, const char* src, unsigned int count)
{
    char* current = dst;
    if (count == 0)
        return dst;
    do {
        if ((*current++ = *src++) == 0) {
            if (--count == 0)
                return dst;
            do {
                *current++ = 0;
            } while (--count);
            return dst;
        }
    } while (--count);
    return dst;
}

// Original: arm9/main @ 0x02004040; symbol: strcat; size: 0x30.
char* strcat(char* dst, const char* src)
{
    char* current = dst;
    while (*current++) {}
    --current;
    while ((*current++ = *src++) != 0) {}
    return dst;
}
