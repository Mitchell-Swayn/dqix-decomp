#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB21C; symbol: Unclassified_SetHalfwordAtOffset26; size: 0x8.
// Stores the supplied halfword at object byte offset 0x26.
extern "C" void Menu_SetSpriteCellParameterAt26(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x26) = value;
}
