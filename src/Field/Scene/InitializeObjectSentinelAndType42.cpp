#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *);
// Original: arm9/ov017 @ 0x021C1E40; symbol: func_ov017_021c1e40; size: 0x2C.
extern "C" void InitializeObjectSentinelAndType42(signed char *object) {
    LinkedQueue_InitializeNodeStatus(object);
    object[0] = 0x42;
    object[0xa] = 0;
    object[0xb] = 0;
    *(short *)(object + 8) = -1;
}
