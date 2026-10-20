#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9C70; symbol: SetHalfwordAtOffset4A_021F9C70; size: 0x8.
// Stores the halfword at object offset 0x4A.
extern "C" void Menu_SetGridSelectButtonCallback(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x4A) = value;
}
