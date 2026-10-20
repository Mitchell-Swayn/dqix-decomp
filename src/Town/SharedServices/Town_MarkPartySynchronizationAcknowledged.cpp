#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x02167240; symbol: func_ov003_02167240; size: 0xC.
extern "C" void Town_MarkPartySynchronizationAcknowledged(void *arg) {
    *(int *)((char *)arg + 0x4b0) = 1;
}
