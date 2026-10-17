#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_0224e204[];
extern "C" int MessageQueue_ReceiveWithOptionalBlocking(void *, unsigned int *, unsigned int);
// Original: arm9/ov031 @ 0x0220510C; symbol: func_ov031_0220510c; size: 0x28.
extern "C" unsigned int ReceiveGlobalQueueValueWithFlags(unsigned int flags) {
    unsigned int value;
    if (MessageQueue_ReceiveWithOptionalBlocking(data_ov031_0224e204, &value, flags))
        return value;
    return 0;
}
