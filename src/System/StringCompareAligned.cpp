#include "std_library_functions.h"

#pragma optimize_for_size off

int strcmp(const char* lhs, const char* rhs)
{
    const unsigned char* left = (const unsigned char*)lhs;
    const unsigned char* right = (const unsigned char*)rhs;
    unsigned int a = *left;
    int difference = a - *right;
    if (difference != 0)
        return difference;
    unsigned int alignment = (uintptr_t)left & 3;
    if (((uintptr_t)right & 3) == alignment) {
        if (alignment != 0) {
            if (a == 0)
                return 0;
            alignment = 3 - alignment;
            if (alignment != 0) {
                do {
                    a = *++left;
                    difference = a - *++right;
                    if (difference != 0)
                        return difference;
                    if (a == 0)
                        return 0;
                } while (--alignment);
            }
            ++left;
            ++right;
        }
        a = *(const uint32_t*)left;
        unsigned int zeroMask = (a + 0xfefefeff) & ~a & 0x80808080;
        unsigned int b = *(const uint32_t*)right;
        if (zeroMask == 0) {
            if (a == b) {
                do {
                    left += 4;
                    right += 4;
                    a = *(const uint32_t*)left;
                    b = *(const uint32_t*)right;
                    // The original loop uses this conservative high-bit shortcut.
                    if ((a + 0xfefefeff) & 0x80808080)
                        goto byte_compare;
                } while (a == b);
            }
            --left;
            --right;
        } else {
byte_compare:
            a = *left;
            difference = a - *right;
            if (difference != 0)
                return difference;
        }
    }
    if (a == 0)
        return 0;
    do {
        a = *++left;
        difference = a - *++right;
        if (difference != 0)
            return difference;
    } while (a != 0);
    return 0;
}
