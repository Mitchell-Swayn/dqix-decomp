#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9C38; symbol: SetHalfwordAtOffset3C; size: 0x8.
// Stores the halfword at object offset 0x3C.
extern "C" void Menu_SetGridXButtonState(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x3C) = value;
}
