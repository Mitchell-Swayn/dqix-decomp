#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
// Original: arm9/ov017 @ 0x021C9AD4; symbol: func_ov017_021c9ad4; size: 0x30.
extern "C" void ApplyQueuedRecordTag56WithInputHalfword(int value) {
    void *object = Network_GetCommandRecordPool();
    unsigned char source[0x14];
    source[0] = 0x56;
    *(short *)(source + 6) = (short)value;
    Network_QueueOutgoingRecord(object, source, 0);
}
