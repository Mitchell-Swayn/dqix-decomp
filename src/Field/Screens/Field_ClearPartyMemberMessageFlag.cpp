#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x0218D4D0; symbol: func_ov017_0218d4d0; size: 0x1C.
extern "C" void Field_ClearPartyMemberMessageFlag(void *object, unsigned bit) {
    unsigned char *p = (unsigned char *)object + 0x4331;
    *p = *p & ~(1u << bit);
}
