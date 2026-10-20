#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);

// Original: arm9/ov017 @ 0x021CEA8C; symbol: func_ov017_021cea8c; size: 0x28.
extern "C" void Network_QueueLocalMemberInteractionExclusion(void) {
    unsigned char record[0x14];
    void *object = Network_GetCommandRecordPool();
    record[0] = 0x32;
    Network_QueueOutgoingRecord(object, record, 0);
}
