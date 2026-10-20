#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9BA0; symbol: GetHalfwordAtOffset24; size: 0x8.
// Returns the halfword at object offset 0x24.
extern "C" unsigned short Menu_GetGridRowCount(void *object) {
    return *(unsigned short *)((unsigned char *)object + 0x24);
}
