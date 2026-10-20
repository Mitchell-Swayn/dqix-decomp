#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9C40; symbol: SetHalfwordAtOffset3E_021F9C40; size: 0x8.
// Stores the halfword at object offset 0x3E.
extern "C" void Menu_SetGridYButtonState(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x3E) = value;
}
