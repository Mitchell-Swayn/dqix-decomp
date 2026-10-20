#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F8C80; symbol: GetHalfwordAtOffset48; size: 0x8.
// Returns the halfword stored at object offset 0x48.
extern "C" unsigned short MenuTextLabel_GetConfirmCallback(void *object) {
    return *(unsigned short *)((unsigned char *)object + 0x48);
}
