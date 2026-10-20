#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B8C70; symbol: func_ov017_021b8c70; size: 0x14.
extern "C" void Field_InitializeZoneTriggerCommand(void *p) {
    *(unsigned char *)p = 14;
    *(int *)((char *)p + 8) = -1;
}
