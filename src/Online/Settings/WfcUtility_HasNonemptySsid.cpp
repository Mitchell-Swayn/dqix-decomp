#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0221B1CC; symbol: Unclassified_HasAnyNonzeroByteInFirst32; size: 0x28.
// Returns one when any of the first 0x20 bytes is nonzero, otherwise zero.
extern "C" unsigned WfcUtility_HasNonemptySsid(const unsigned char *bytes) {
    int i = 0;
    do {
        if (bytes[i])
            return 1;
        ++i;
    } while (i < 0x20);
    return 0;
}
