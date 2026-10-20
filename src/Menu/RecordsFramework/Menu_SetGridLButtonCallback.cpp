#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9CA8; symbol: Unclassified_SetHalfwordAtOffset58; size: 0x8.
// Stores the supplied halfword at object byte offset 0x58.
extern "C" void Menu_SetGridLButtonCallback(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x58) = value;
}
