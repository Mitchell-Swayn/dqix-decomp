#include <globaldefs.h>

#pragma dont_inline on

extern "C" {
// Original data: arm9/main @ 0x20ee278; symbol: data_020ee278.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000963007772c610eeeba51099919c46d078ff46a7035a563e9a395649e3288db0ea4b8dc791ee9d5e088d9d2972b4cb609bd7cb17e072db8e7911dbf90 ...; full span in module reference.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const unsigned int FileCacheUpdateCRCWithByte_UnknownRoleInitializedBytes[256];
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
    return FileCacheUpdateCRCWithByte_UnknownRoleInitializedBytes[(crc ^ byte) & 255] ^ (crc >> 8);
}

}
