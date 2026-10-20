#include <globaldefs.h>
THUMB
// Original: arm9/ov031 @ 0x022227C0; symbol: func_ov031_022227c0; size: 0x2C.
extern "C" void Memory_CopyWordsAsBytes(unsigned char *destination, const unsigned int *source, unsigned int length) {
    unsigned int offset = 0;
    while (offset < length) {
        destination[offset] = (unsigned char)source[0];
        destination[offset + 1] = (unsigned char)(source[0] >> 8);
        destination[offset + 2] = (unsigned char)(source[0] >> 16);
        destination[offset + 3] = (unsigned char)(source[0] >> 24);
        source++;
        offset += 4;
    }
}
