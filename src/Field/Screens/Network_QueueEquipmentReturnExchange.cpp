#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
// Original: arm9/ov017 @ 0x021D27A0; symbol: func_ov017_021d27a0; size: 0x44.
extern "C" void Network_QueueEquipmentReturnExchange(unsigned char a, unsigned char b, unsigned char c) {
    void *object = Network_GetCommandRecordPool();
    unsigned char source[0x14];
    source[0] = 0x22;
    unsigned char *payload = source + 4;
    payload[0] = a;
    payload[1] = b;
    payload[2] = c;
    Network_QueueOutgoingRecord(object, source, 0);
}
