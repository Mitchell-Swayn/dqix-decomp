#include <globaldefs.h>
THUMB
// Original: arm9/ov031 @ 0x0221E6E0; symbol: Unclassified_InitializePointerStatusPair; size: 0x8.
// Writes the object pointer to output word 0 and sets the unsigned halfword at output+4 to 1; returns 1.
extern "C" int WirelessSetup_InitializeSocketPollRecord(void *object, void *output) {
    *(void **)output = object;
    *(unsigned short *)((unsigned char *)output + 4) = 1;
    return 1;
}
