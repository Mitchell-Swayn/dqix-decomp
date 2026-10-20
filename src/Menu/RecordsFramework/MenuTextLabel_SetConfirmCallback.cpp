#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F8C78; symbol: SetHalfwordAtOffset48; size: 0x8.
// Stores the supplied halfword at object offset 0x48.
extern "C" void MenuTextLabel_SetConfirmCallback(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x48) = value;
}
