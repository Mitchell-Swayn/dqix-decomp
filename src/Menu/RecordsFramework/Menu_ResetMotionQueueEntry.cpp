#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9EB4; symbol: func_ov023_021f9eb4; size: 0x14.
extern "C" void Menu_ResetMotionQueueEntry(void *record) {
    *(unsigned short *)record = 0;
    *((unsigned char *)record + 2) = 0;
    *((unsigned char *)record + 3) = 0;
}
