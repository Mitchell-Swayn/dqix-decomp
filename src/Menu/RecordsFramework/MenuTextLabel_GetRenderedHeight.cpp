#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F8C60; symbol: GetHalfwordAtOffset40; size: 0x8.
// Returns the halfword stored at object offset 0x40.
extern "C" unsigned short MenuTextLabel_GetRenderedHeight(void *object) {
    return *(unsigned short *)((unsigned char *)object + 0x40);
}
