#include "System/RuntimeDecimal.h"

#pragma optimize_for_size off

extern "C" void func_020096ac(RuntimeDecimal* decimal, unsigned long long value)
{
    decimal->sign = 0;
    decimal->length = 0;
    if (value) {
        do {
            unsigned int index = decimal->length++;
            decimal->digits[index] = value % 10;
            value /= 10;
        } while (value);
    }
    unsigned char* first = decimal->digits;
    unsigned char* last = first + decimal->length - 1;
    if (first < last) do {
        unsigned char digit = *first;
        *first++ = *last;
        *last-- = digit;
    } while (first < last);
    decimal->exponent = decimal->length - 1;
}
