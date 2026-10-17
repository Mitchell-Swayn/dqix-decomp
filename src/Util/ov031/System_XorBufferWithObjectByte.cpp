#include <globaldefs.h>
THUMB
extern "C" int func_ov031_0221e27c(const unsigned char *);
// Original: arm9/ov031 @ 0x0221E250; symbol: func_ov031_0221e250; size: 0x2C.
extern "C" void System_XorBufferWithObjectByte(void *key, unsigned char *destination, const unsigned char *source, unsigned int length) {
    unsigned int i = 0;
    if (length != 0) {
        do {
            unsigned char mask = (unsigned char)func_ov031_0221e27c((const unsigned char *)key);
            destination[i] = source[i] ^ mask;
            ++i;
        } while (i < length);
    }
}
