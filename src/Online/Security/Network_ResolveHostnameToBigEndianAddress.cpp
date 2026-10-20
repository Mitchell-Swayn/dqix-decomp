#include <globaldefs.h>
ARM
extern "C" unsigned System_RunWithIRQDisabledAndRestoreSharedPair(unsigned);
// Original: arm9/ov031 @ 0x022077CC; symbol: ConvertWordAndWriteByteReversed; size: 0x50.
extern "C" int Network_ResolveHostnameToBigEndianAddress(unsigned input, unsigned *output) {
    unsigned value = System_RunWithIRQDisabledAndRestoreSharedPair(input);
    if (value == 0) return 0;
    *output = ((value >> 24) & 0xff) | ((value >> 8) & 0xff00) | ((value << 8) & 0xff0000) | ((value << 24) & 0xff000000);
    return 1;
}
