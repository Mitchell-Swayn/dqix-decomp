#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x0218D4EC; symbol: func_ov017_0218d4ec; size: 0x14.
extern "C" unsigned int Field_TestPartyMemberMessageFlag(void *object, unsigned int bit) {
    return *(unsigned char *)((char *)object + 0x4331) & (1u << bit);
}
