#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F8C88; symbol: SetHalfwordAtOffset4A; size: 0x8.
// Stores the supplied halfword at object offset 0x4A.
extern "C" void MenuTextLabel_SetSelectionChangedCallback(void *object, unsigned short value) {
    *(unsigned short *)((unsigned char *)object + 0x4A) = value;
}
