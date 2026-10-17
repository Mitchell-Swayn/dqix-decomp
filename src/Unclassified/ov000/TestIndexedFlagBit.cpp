#include <globaldefs.h>

// Original: arm9/ov000 @ 0x0217c4e8; symbol: func_ov000_0217c4e8; size: 0x2c.
extern "C" int TestIndexedFlagBit(void* bytes, int bitIndex) {
    unsigned int byteIndex = ((int)bitIndex >> 3) & 0xff;
    volatile unsigned char* selected = (volatile unsigned char*)bytes + byteIndex;
    unsigned char mask = (unsigned char)(1u << (bitIndex & 7));
    unsigned char value = selected[0x88];
    return (value & mask) != 0;
}
