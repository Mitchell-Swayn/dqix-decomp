#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
// Original: arm9/ov017 @ 0x021CFED0; symbol: func_ov017_021cfed0; size: 0x3C.
extern "C" void Field_QueueTargetedPartyRosterRefresh(unsigned char first, unsigned char second) {
    unsigned char source[0x14];
    void *object = Network_GetCommandRecordPool();
    source[0] = 0x16;
    unsigned char *payload = source + 4;
    payload[0] = first;
    payload[1] = second;
    Network_QueueOutgoingRecord(object, source, 0);
}
