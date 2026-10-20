#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9CA0; symbol: Unclassified_SetHalfwordAtOffset56; size: 0x8.
// Stores the supplied halfword at object byte offset 0x56.
extern "C" void Menu_SetGridLeftCallback(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x56) = value;
}
