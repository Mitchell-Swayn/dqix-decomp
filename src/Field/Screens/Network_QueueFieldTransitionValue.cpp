#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void *object, const void *source, short value);
// Original: arm9/ov017 @ 0x021D23BC; symbol: func_ov017_021d23bc; size: 0x30.
extern "C" void Network_QueueFieldTransitionValue(short sourceValue) {
    void *object = Network_GetCommandRecordPool();
    unsigned char record[0x14];
    record[0] = 0x9E;
    *(short *)(record + 4) = sourceValue;
    Network_QueueOutgoingRecord(object, record, 0);
}
