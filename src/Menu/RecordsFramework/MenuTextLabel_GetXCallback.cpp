#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F8CA0; symbol: GetHalfwordAtOffset4C; size: 0x8.
// Returns the halfword stored at object offset 0x4C.
extern "C" unsigned short MenuTextLabel_GetXCallback(void *object) {
    return *(unsigned short *)((unsigned char *)object + 0x4C);
}
