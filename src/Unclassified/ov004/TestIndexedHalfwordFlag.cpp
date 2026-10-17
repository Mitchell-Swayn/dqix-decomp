// Returns the selected bit from the halfword at object+0xA54.
// Original: arm9/ov004 @ 0x0215EB20; symbol: func_ov004_0215eb20; size: 0x20.
extern "C" unsigned short TestIndexedHalfwordFlag(const unsigned char* object, unsigned int bit) {
    const unsigned char* flags = *(const unsigned char* const*)(object + 0x150) + 0x900;
    return (unsigned short)(*(const unsigned short*)(flags + 0x54) & (1u << bit));
}
