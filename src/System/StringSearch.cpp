#include "std_library_functions.h"

#pragma optimize_for_size off

int strncmp(const char* lhs, const char* rhs, unsigned int count)
{
    const unsigned char* left = (const unsigned char*)lhs;
    const unsigned char* right = (const unsigned char*)rhs;
    if (count != 0) {
        do {
            unsigned char b = *right++;
            unsigned char a = *left++;
            if (a != b)
                return a - b;
            if (a == 0)
                break;
        } while (--count);
    }
    return 0;
}

char* strchr(const char* str, int ch)
{
    char value = *str++;
    char target = (char)ch;
    if (value != 0) {
        do {
            if (value == target)
                return (char*)str - 1;
            value = *str++;
        } while (value != 0);
    }
    return target != 0 ? 0 : (char*)str - 1;
}

char* strrchr(const char* str, int ch)
{
    const char* current = str;
    char target = (char)ch;
    char* result = 0;
    char value = *current++;
    if (value != 0) {
        do {
            if (value == target)
                result = (char*)current - 1;
            value = *current++;
        } while (value != 0);
    }
    if (result)
        return result;
    return target != 0 ? 0 : (char*)current - 1;
}

char* strstr(const char* str, const char* substr)
{
    const unsigned char* candidate = (const unsigned char*)str;
    const unsigned char* needle = (const unsigned char*)substr;
    unsigned char first;
    if (needle == 0 || (first = *needle) == 0)
        return (char*)str;
    unsigned char value = *candidate++;
    if (value != 0) {
        do {
            if (value == first) {
                const unsigned char* haystack = candidate;
                const unsigned char* pattern = needle + 1;
                unsigned char a, b;
                do {
                    b = *pattern++;
                    a = *haystack++;
                } while (a == b && a != 0);
                if (b == 0)
                    return (char*)candidate - 1;
            }
            value = *candidate++;
        } while (value != 0);
    }
    return 0;
}
