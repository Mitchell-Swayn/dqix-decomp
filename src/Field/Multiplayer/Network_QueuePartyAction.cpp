#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021CED48; symbol: func_ov017_021ced48; size: 0x3C.
extern "C" void Network_QueuePartyAction(unsigned char first, unsigned char second) {
    void* object = Network_GetCommandRecordPool();
    unsigned char record[20];
    unsigned char* fields = record + 4;
    record[0] = 0x35;
    fields[0] = first;
    fields[1] = second;
    Network_QueueOutgoingRecord(object, record, 0);
}
