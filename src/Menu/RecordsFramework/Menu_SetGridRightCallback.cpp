#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9C98; symbol: Unclassified_SetHalfwordAtOffset54; size: 0x8.
// Stores the supplied halfword at object byte offset 0x54.
extern "C" void Menu_SetGridRightCallback(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x54) = value;
}
