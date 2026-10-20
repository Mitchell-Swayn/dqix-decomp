#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
struct TaggedSourceRecord {
    unsigned char tag;
    unsigned char padding[3];
    short value;
    unsigned char trailing[0xe];
};
// Original: arm9/ov017 @ 0x021CC050; symbol: func_ov017_021cc050; size: 0x30.
extern "C" void Resource_MoveQueuedRecordWithTaggedInput(short value) {
    void *destination = Network_GetCommandRecordPool();
    TaggedSourceRecord source;
    source.tag = 0x82;
    source.value = value;
    Network_QueueOutgoingRecord(destination, &source, 0);
}
