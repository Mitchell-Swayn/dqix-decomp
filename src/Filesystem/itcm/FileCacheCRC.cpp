#include <globaldefs.h>

#pragma dont_inline on

extern "C" {
extern const unsigned int data_020ee278[256];
unsigned int func_01ff85f0(unsigned int byte, unsigned int crc);

// Reflected CRC-32, with all-one initial state and final complement.
unsigned int func_01ff85b8(const unsigned char* bytes, unsigned int length)
{
    unsigned int crc = ~0u;
    if (bytes != NULL)
        while (length != 0) {
            crc = func_01ff85f0(*bytes++, crc);
            --length;
        }
    return ~crc;
}

unsigned int func_01ff85f0(unsigned int byte, unsigned int crc)
{
    return data_020ee278[(crc ^ byte) & 255] ^ (crc >> 8);
}

}
