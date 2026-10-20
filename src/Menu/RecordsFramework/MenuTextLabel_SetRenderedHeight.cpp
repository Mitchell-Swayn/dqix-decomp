#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F8C58; symbol: SetHalfwordAtOffset40; size: 0x8.
// Stores the supplied halfword at object offset 0x40.
extern "C" void MenuTextLabel_SetRenderedHeight(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x40) = value;
}
