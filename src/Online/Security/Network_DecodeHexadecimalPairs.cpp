#include <globaldefs.h>
THUMB
// Original: arm9/ov031 @ 0x022208B4; symbol: func_ov031_022208b4; size: 0xB4.
extern "C" int Network_DecodeHexadecimalPairs(unsigned char *out, const char *input, int length) {
    int c;
    int value = 0;
    int i = 0;
    for (; i < length; ++i) {
        c = input[i];
        switch (c) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            value += c - '0'; break;
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
            value += c - 'a' + 10; break;
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
            value += c - 'A' + 10; break;
        default: return 0;
        }
        if (i % 2 == 0) value <<= 4;
        else { out[i / 2] = value; value = 0; }
    }
    return 1;
}
