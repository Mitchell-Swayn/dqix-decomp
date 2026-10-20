#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9C68; symbol: SetHalfwordAtOffset48_021F9C68; size: 0x8.
// Stores the halfword at object offset 0x48.
extern "C" void Menu_SetGridPageChangeCallback(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x48) = value;
}
