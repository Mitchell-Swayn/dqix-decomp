#include "std_library_functions.h"

// Original: arm9/main @ 0x02003F0C; symbol: strlen; size: 0x1C.
unsigned int strlen(const char* str)
{
    unsigned int length = -1;
    do {
        ++length;
    } while (*str++);
    return length;
}
