#include <globaldefs.h>

#pragma dont_inline on

extern "C" {
extern const unsigned int data_020ee278[256];
unsigned int FileCache_UpdateCRCWithByte(unsigned int byte, unsigned int crc);

// Reflected CRC-32, with all-one initial state and final complement.
// Original: arm9/itcm @ 0x01FF85B8; symbol: func_01ff85b8; size: 0x38.
unsigned int FileCache_ComputeCRC32(const unsigned char* bytes, unsigned int length)
{
    unsigned int crc = ~0u;
    if (bytes != NULL)
        while (length != 0) {
            crc = FileCache_UpdateCRCWithByte(*bytes++, crc);
            --length;
        }
    return ~crc;
}

// Original: arm9/itcm @ 0x01FF85F0; symbol: func_01ff85f0; size: 0x1C.
unsigned int FileCache_UpdateCRCWithByte(unsigned int byte, unsigned int crc)
{
    return data_020ee278[(crc ^ byte) & 255] ^ (crc >> 8);
}

}
