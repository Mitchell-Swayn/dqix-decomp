#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0220B18C; symbol: func_ov031_0220b18c; size: 0x44.
extern "C" void Util_StoreWordsMostSignificantByteFirst(unsigned char *dst, const unsigned int *src, unsigned byteCount) {
    byteCount >>= 2;
    unsigned i = 0;
    if (byteCount == 0) return;
    do {
        unsigned int value = *src++;
        dst[0] = (unsigned char)(value >> 24);
        dst[1] = (unsigned char)(value >> 16);
        dst[2] = (unsigned char)(value >> 8);
        dst[3] = (unsigned char)value;
        dst += 4;
    } while (++i < byteCount);
}
