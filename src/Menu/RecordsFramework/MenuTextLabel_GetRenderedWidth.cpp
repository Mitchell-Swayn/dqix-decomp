#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F8C50; symbol: GetHalfwordAtOffset3E; size: 0x8.
// Returns the halfword stored at object offset 0x3E.
extern "C" unsigned short MenuTextLabel_GetRenderedWidth(void *object) {
    return *(unsigned short *)((unsigned char *)object + 0x3E);
}
