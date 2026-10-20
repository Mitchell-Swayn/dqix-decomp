#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
// Original: arm9/ov017 @ 0x021C9B90; symbol: func_ov017_021c9b90; size: 0x38.
extern "C" void InitializeQueuedRecordOwner(short owner, short value) {
    void *object = Network_GetCommandRecordPool();
    unsigned char record[0x14];
    record[0] = 0x7b;
    *(short *)(record + 4) = owner;
    *(short *)(record + 6) = value;
    Network_QueueOutgoingRecord(object, record, 0);
}
