#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F8C98; symbol: SetHalfwordAtOffset4C; size: 0x8.
// Stores the supplied halfword at object offset 0x4C.
extern "C" void MenuTextLabel_SetXCallback(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x4C) = value;
}
