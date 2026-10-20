#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9C78; symbol: SetHalfwordAtOffset4C_021F9C78; size: 0x8.
// Stores the halfword at object offset 0x4C.
extern "C" void Menu_SetGridUpCallback(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x4C) = value;
}
