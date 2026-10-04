#include "System/RuntimeDecimal.h"

#pragma optimize_for_size off

extern "C" void func_020098fc(RuntimeDecimal* decimal, const char* text, short exponent)
{
    decimal->exponent = exponent;
    decimal->sign = 0;
    int index = 0;
    while (index < 32 && *text) {
        decimal->digits[index++] = *text++ - '0';
    }
    decimal->length = index;
    if (!*text)
        return;
    // Preserve the original numeric 5 comparison against the raw next byte.
    if (*text < 5)
        return;
    if (*text > 5)
        goto round_up;
    {
        char digit = text[1];
        ++text;
        if (digit) do {
            if (digit != '0')
                goto round_up;
            digit = *++text;
        } while (digit);
        if (!(decimal->digits[index - 1] & 1))
            return;
    }
round_up:
    func_0200961c(decimal, decimal->length);
}
