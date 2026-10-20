#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F8C90; symbol: GetHalfwordAtOffset4A; size: 0x8.
// Returns the halfword stored at object offset 0x4A.
extern "C" unsigned short MenuTextLabel_GetSelectionChangedCallback(void *object) {
    return *(unsigned short *)((unsigned char *)object + 0x4A);
}
