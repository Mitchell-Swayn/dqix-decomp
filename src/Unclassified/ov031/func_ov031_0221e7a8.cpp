#include <globaldefs.h>
THUMB
extern "C" unsigned data_ov031_0224f4e0;
extern "C" int OS_SendMessage(void *queue, void *message, int flags);
// Original: arm9/ov031 @ 0x0221E7A8; symbol: func_ov031_0221e7a8; size: 0x14.
extern "C" int func_ov031_0221e7a8(void *message) {
    return OS_SendMessage(&data_ov031_0224f4e0, message, 0);
}
