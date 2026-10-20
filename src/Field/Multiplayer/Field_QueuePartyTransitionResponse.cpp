#include <globaldefs.h>
ARM

extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *object, const void *source, short value);

// Original: arm9/ov017 @ 0x021CF4B0; symbol: func_ov017_021cf4b0; size: 0x38.
extern "C" void Field_QueuePartyTransitionResponse(unsigned char first, unsigned char second) {
    unsigned char record[0x14];
    void *object = Network_GetCommandRecordPool();
    record[0] = 0x39;
    record[4] = first;
    record[5] = second;
    Network_QueueOutgoingRecord(object, record, 0);
}
