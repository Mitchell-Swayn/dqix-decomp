#include <globaldefs.h>
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D035C; symbol: func_ov017_021d035c; size: 0x44.
extern "C" void Network_QueuePartyControlLock(unsigned char first, unsigned char second, unsigned char third) {
    unsigned char packet[0x14];
    void* object = Network_GetCommandRecordPool();
    packet[0] = 0x96;
    unsigned char* output = packet + 4;
    output[0] = first;
    output[1] = second;
    output[2] = third;
    Network_QueueOutgoingRecord(object, packet, 0);
}
