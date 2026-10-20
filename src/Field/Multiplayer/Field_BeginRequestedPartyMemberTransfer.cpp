#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B0490; symbol: Unclassified_CheckByte9AndResetFields23And24; size: 0x30.
// If byte 9 is zero and the pointer at +0x30 is nonnull, clears bytes +0x23 and +0x24 and returns 9; otherwise returns byte +0x0a.
extern "C" int Field_BeginRequestedPartyMemberTransfer(void *object) {
    unsigned char *p = (unsigned char *)object;
    if (p[9] == 0 && *(void **)(p + 0x30) != 0) {
        p[0x23] = 0;
        p[0x24] = 0;
        return 9;
    }
    return p[0x0a];
}
