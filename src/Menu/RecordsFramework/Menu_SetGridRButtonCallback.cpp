#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9CB0; symbol: Unclassified_SetHalfwordAtOffset5A; size: 0x8.
// Stores the supplied halfword at object byte offset 0x5a.
extern "C" void Menu_SetGridRButtonCallback(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x5a) = value;
}
