#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB22C; symbol: Unclassified_SetHalfwordAtOffset3C; size: 0x8.
// Stores the supplied halfword at object byte offset 0x3c.
extern "C" void Menu_SetSpriteCellTouchPressCallback(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x3c) = value;
}
