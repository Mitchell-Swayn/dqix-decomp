#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9BB8; symbol: SetHalfwordAtOffset2A; size: 0x8.
// Stores the halfword at object offset 0x2A.
extern "C" void Menu_SetSelectedGridColumn(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x2A) = value;
}
