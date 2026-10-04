#include "std_library_functions.h"

#pragma optimize_for_size off

char* strcpy(char* dst, const char* src)
{
    unsigned char* output = (unsigned char*)dst;
    const unsigned char* input = (const unsigned char*)src;
    unsigned int alignment = (uintptr_t)input & 3;
    if (((uintptr_t)output & 3) == alignment) {
        if (alignment != 0) {
            unsigned char value = *input;
            *output = value;
            if (value == 0)
                return dst;
            alignment = 3 - alignment;
            if (alignment != 0) {
                do {
                    value = *++input;
                    *++output = value;
                    if (value == 0)
                        return dst;
                } while (--alignment);
            }
            ++output;
            ++input;
        }
        uint32_t word = *(const uint32_t*)input;
        // Keep the two zero-byte test terms explicit to preserve register allocation.
        uint32_t sum = word + 0xfefefeff;
        uint32_t inverse = ~word;
        if ((sum & inverse & 0x80808080) == 0) {
            output -= 4;
            do {
                output += 4;
                *(uint32_t*)output = word;
                input += 4;
                word = *(const uint32_t*)input;
                sum = word + 0xfefefeff;
                inverse = ~word;
            } while ((sum & inverse & 0x80808080) == 0);
            output += 4;
        }
    }
    unsigned char value = *input;
    *output = value;
    if (value == 0)
        return dst;
    do {
        value = *++input;
        *++output = value;
    } while (value != 0);
    return dst;
}
