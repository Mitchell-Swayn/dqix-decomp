#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0221563C; symbol: func_ov031_0221563c; size: 0x54.
// Builds an all-ones network prefix mask, then reverses its byte order for address settings.
extern "C" unsigned Network_BuildByteSwappedPrefixMask(int prefixLength) {
    int shifts = 32 - prefixLength;
    unsigned mask = ~0u;
    for (prefixLength = 0; prefixLength < shifts; ++prefixLength) mask <<= 1;
    return (((mask >> 24) & 0xff) | ((mask >> 8) & 0xff00)) |
           ((mask << 8) & 0xff0000) | ((mask << 24) & 0xff000000);
}
