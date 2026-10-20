#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9C60; symbol: SetHalfwordAtOffset46_021F9C60; size: 0x8.
// Stores the halfword at object offset 0x46.
extern "C" void Menu_SetGridCancelCallback(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x46) = value;
}
