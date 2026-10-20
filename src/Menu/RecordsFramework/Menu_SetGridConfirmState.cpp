#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9C50; symbol: SetHalfwordAtOffset42; size: 0x8.
// Stores the halfword at object offset 0x42.
extern "C" void Menu_SetGridConfirmState(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x42) = value;
}
