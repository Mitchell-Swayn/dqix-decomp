#include <globaldefs.h>
ARM
extern "C" int Combat_IsActionMessageQueueIdle(void *object);
// Original: arm9/ov025 @ 0x021E9528; symbol: func_ov025_021e9528; size: 0x30.
extern "C" int Combat_IsActionProgramAndMessageQueueIdle(void *object) {
    if (*(int *)((char *)object + 4))
        return 0;
    return Combat_IsActionMessageQueueIdle((char *)object + 0x5e8) != 0;
}
