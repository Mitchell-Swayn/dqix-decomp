#include "std_library_functions.h"

#pragma optimize_for_size off

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

char* strcat(char* dst, const char* src)
{
    char* current = dst;
    while (*current++) {}
    --current;
    while ((*current++ = *src++) != 0) {}
    return dst;
}
