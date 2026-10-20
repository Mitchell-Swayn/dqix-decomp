#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB224; symbol: Unclassified_GetHalfwordAtOffset26; size: 0x8.
// Returns the unsigned halfword at object byte offset 0x26.
extern "C" unsigned short Menu_GetSpriteCellParameterAt26(void *object) {
    return *(unsigned short *)((unsigned char *)object + 0x26);
}
