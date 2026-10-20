#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D257C; symbol: func_ov017_021d257c; size: 0x3C.
extern "C" void Resource_ApplyQueuedRecordKind31(unsigned char kind, unsigned value) {
    unsigned char record[0x14];
    void* object = Network_GetCommandRecordPool();
    record[0] = 0x1f;
    unsigned char* payload = record + 4;
    *payload = kind;
    *(unsigned*)(payload + 4) = value;
    Network_QueueOutgoingRecord(object, record, 0);
}
