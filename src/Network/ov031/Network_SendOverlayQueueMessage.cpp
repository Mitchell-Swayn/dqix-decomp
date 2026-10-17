#include <globaldefs.h>
THUMB
extern "C" unsigned char data_ov031_0224f4e0[];
extern "C" int OS_SendMessage(void *queue, void *message, int flags);
// Original: arm9/ov031 @ 0x0221E7BC; symbol: func_ov031_0221e7bc; size: 0x14.
extern "C" int Network_SendOverlayQueueMessage(void *message) {
    return OS_SendMessage((void *)data_ov031_0224f4e0, message, 0);
}
