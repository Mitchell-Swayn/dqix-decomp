#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02204B50; symbol: Util_ParseDecimalAndAdvanceCursor; size: 0x34.
// Accumulates consecutive decimal digits and advances the cursor to the first non-digit.
extern "C" int Util_ParseDecimalAndAdvanceCursor(unsigned char* input, unsigned char** cursor) {
    *cursor = input;
    int value = 0;
    for (;;) {
        unsigned char digit = (unsigned char)(*input - '0');
        if (digit > 9) break;
        value = value * 10 + digit;
        ++input;
        *cursor = input;
    }
    return value;
}
