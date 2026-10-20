#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9C80; symbol: Unclassified_SetHalfwordAtOffset4E; size: 0x8.
// Stores the supplied halfword at object byte offset 0x4e.
extern "C" void Menu_SetGridDownCallback(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x4e) = value;
}
