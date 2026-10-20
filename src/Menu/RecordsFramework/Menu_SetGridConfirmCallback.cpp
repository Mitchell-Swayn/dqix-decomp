#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9C48; symbol: SetHalfwordAtOffset40_021F9C48; size: 0x8.
// Stores the halfword at object offset 0x40.
extern "C" void Menu_SetGridConfirmCallback(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x40) = value;
}
