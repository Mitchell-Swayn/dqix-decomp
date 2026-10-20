#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
// Original: arm9/ov017 @ 0x021CF594; symbol: func_ov017_021cf594; size: 0x40.
extern "C" void Field_QueueTargetedZoneTransition(unsigned short value, unsigned char first, unsigned char second) {
    void *object = Network_GetCommandRecordPool();
    unsigned char source[0x14];
    source[0] = 0x3A;
    *(unsigned short *)(source + 4) = value;
    source[6] = first;
    source[7] = second;
    Network_QueueOutgoingRecord(object, source, 0);
}
