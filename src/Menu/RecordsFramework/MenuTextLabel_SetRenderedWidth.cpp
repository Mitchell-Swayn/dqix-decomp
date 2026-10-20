#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F8C48; symbol: SetHalfwordAtOffset3E; size: 0x8.
// Stores the supplied halfword at object offset 0x3E.
extern "C" void MenuTextLabel_SetRenderedWidth(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x3E) = value;
}
