#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F8C70; symbol: GetHalfwordAtOffset46; size: 0x8.
// Returns the halfword stored at object offset 0x46.
extern "C" unsigned short MenuTextLabel_GetConfirmStateRoute(void *object) {
    return *(unsigned short *)((unsigned char *)object + 0x46);
}
