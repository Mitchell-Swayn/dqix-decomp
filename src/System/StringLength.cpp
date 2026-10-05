#include "std_library_functions.h"

unsigned int strlen(const char* str)
{
    unsigned int length = -1;
    do {
        ++length;
    } while (*str++);
    return length;
}
