#include <globaldefs.h>
ARM
extern "C" unsigned data_ov031_022918bc;
extern "C" int MessageQueue_ReceiveWithOptionalBlocking(void *queue, unsigned *output, unsigned flags);
// Original: arm9/ov031 @ 0x022403D8; symbol: func_ov031_022403d8; size: 0x1C.
extern "C" int func_ov031_022403d8(void) {
    unsigned message;
    return MessageQueue_ReceiveWithOptionalBlocking(&data_ov031_022918bc, &message, 1);
}
