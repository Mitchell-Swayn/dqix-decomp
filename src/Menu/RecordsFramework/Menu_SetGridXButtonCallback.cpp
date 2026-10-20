#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9C90; symbol: Unclassified_SetHalfwordAtOffset52; size: 0x8.
// Stores the supplied halfword at object byte offset 0x52.
extern "C" void Menu_SetGridXButtonCallback(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x52) = value;
}
