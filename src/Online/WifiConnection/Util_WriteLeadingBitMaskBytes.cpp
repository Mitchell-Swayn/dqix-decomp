#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0221B19C; symbol: Util_WriteLeadingBitMaskBytes; size: 0x30.
// Builds the high-bit mask for the requested bit count and writes its four bytes most-significant first.
extern "C" void Util_WriteLeadingBitMaskBytes(unsigned int bits, unsigned char *out) {
    unsigned int mask = 0xffffffffu ^ (0xffffffffu >> bits);
    int i = 0;
    unsigned int ip = 0;
    do {
        out[i] = (unsigned char)(mask >> (24 - ip));
        ++i;
        ip += 8;
    } while (i < 4);
}
