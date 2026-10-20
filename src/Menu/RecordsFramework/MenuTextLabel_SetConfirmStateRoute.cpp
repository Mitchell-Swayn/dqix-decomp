#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F8C68; symbol: SetHalfwordAtOffset46; size: 0x8.
// Stores the supplied halfword at object offset 0x46.
extern "C" void MenuTextLabel_SetConfirmStateRoute(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x46) = value;
}
