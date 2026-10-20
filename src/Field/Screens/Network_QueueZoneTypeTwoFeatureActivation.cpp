#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
struct Payload { unsigned short first; unsigned short second; unsigned word; };
struct Record { unsigned char type; unsigned char pad[3]; Payload payload; unsigned char spare[8]; };
// Original: arm9/ov017 @ 0x021D196C; symbol: Zone3D_QueueTypeAfRecordForType2Feature; size: 0x44.
// Called by Zone3D::ActivateType2Feature; builds a type-0xAF record with two halfwords and a word, then queues it with value zero.
extern "C" void Network_QueueZoneTypeTwoFeatureActivation(unsigned short first, unsigned short second, unsigned word) {
    void *object = Network_GetCommandRecordPool();
    Record record;
    Payload *payload = &record.payload;
    record.type = 0xaf;
    payload->first = first;
    payload->second = second;
    payload->word = word;
    Network_QueueOutgoingRecord(object, &record, 0);
}
