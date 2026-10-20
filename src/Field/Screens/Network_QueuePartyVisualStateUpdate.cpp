#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D2C34; symbol: func_ov017_021d2c34; size: 0x44.
extern "C" void Network_QueuePartyVisualStateUpdate(unsigned char a, unsigned char b, unsigned char c) {
    unsigned char record[0x14];
    void* owner = Network_GetCommandRecordPool();
    unsigned char* payload = record + 4;
    record[0] = 0x24;
    payload[0] = a;
    payload[1] = b;
    payload[2] = c;
    Network_QueueOutgoingRecord(owner, record, 0);
}
