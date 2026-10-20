#include <globaldefs.h>
ARM
// Original: arm9/ov016 @ 0x0218E7BC; symbol: Memory_ClearRecordWordsAtSelectedOffsets; size: 0x30.
// Clears the record words at offsets 0, 0x58 through 0x74, and 0x94.
extern "C" void Memory_ClearRecordWordsAtSelectedOffsets(unsigned int *p) {
    unsigned int z = 0;
    p[0] = z;
    p[0x5c / 4] = z;
    p[0x60 / 4] = z;
    p[0x68 / 4] = z;
    p[0x6c / 4] = z;
    p[0x70 / 4] = z;
    p[0x74 / 4] = z;
    p[0x64 / 4] = z;
    p[0x58 / 4] = z;
    p[0x94 / 4] = z;
}
