#include <globaldefs.h>
ARM
struct Payload { short first; short second; unsigned char third; };
struct Record { unsigned char type; unsigned char padding[3]; Payload payload; unsigned char tail[8]; };
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D1810; symbol: func_ov017_021d1810; size: 0x44.
extern "C" void Network_QueueTypeAdRecord(short first, short second, unsigned char third) {
    void *object = Network_GetCommandRecordPool();
    Record record;
    record.type = 0xad;
    Payload *payload = &record.payload;
    payload->first = first;
    payload->second = second;
    payload->third = third;
    Network_QueueOutgoingRecord(object, &record, 0);
}
