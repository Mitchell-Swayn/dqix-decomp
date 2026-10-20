#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void *, int, unsigned int);
// Original: arm9/ov031 @ 0x0220C8D0; symbol: Graphics_PackReverseBytePairsIntoHalfwords; size: 0x5C.
// Zeroes the halfword output, packs source bytes in reverse pairs into halfwords, and writes a final odd byte when present.
extern "C" void Graphics_PackReverseBytePairsIntoHalfwords(unsigned short *dst, const unsigned char *src, int count, unsigned int capacity) {
    VectorizedMemset(dst, 0, capacity * 2);
    src += count - 1;
    if (count > 1) {
        do {
            unsigned int value = src[0] + (src[-1] << 8);
            *dst++ = (unsigned short)value;
            count -= 2;
            src -= 2;
        } while (count > 1);
    }
    if (count > 0) *dst = *src;
}
