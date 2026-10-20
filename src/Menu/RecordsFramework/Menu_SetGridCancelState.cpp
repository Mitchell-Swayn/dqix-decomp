#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9C58; symbol: SetHalfwordAtOffset44; size: 0x8.
// Stores the halfword at object offset 0x44.
extern "C" void Menu_SetGridCancelState(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x44) = value;
}
