#include <globaldefs.h>
// Copy ASCII characters with lowercase letters converted to uppercase.
// The original stops before the input NUL and does not write a terminator.
// Original: arm9/ov012 @ 0x021855F0; symbol: func_ov012_021855f0; size: 0x44.
extern "C" void ProfileTextFilter_CopyUppercaseAscii(void*, const signed char* input, signed char* output)
{
    while (*input) {
        int copied;
        if (*input >= 'a' && *input <= 'z')
            copied = (*output = *input - 32);
        else
            copied = (*output = *input);
        if (copied) ++input;
        ++output;
    }
}
