#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D2738; symbol: func_ov017_021d2738; size: 0x3C.
extern "C" void Network_QueuePartyMemberOverlayToggle(unsigned char first, unsigned char second) {
    unsigned char record[0x14];
    void* destination = Network_GetCommandRecordPool();
    record[0] = 0x21;
    unsigned char* fields = record + 4;
    fields[0] = first;
    fields[1] = second;
    Network_QueueOutgoingRecord(destination, record, 0);
}
