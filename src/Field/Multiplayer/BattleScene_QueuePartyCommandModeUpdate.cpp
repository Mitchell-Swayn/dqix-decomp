#include <globaldefs.h>
ARM
// Original: arm9/ov017:021cefe0; Builds a tag-0x6c queued record from one halfword and two byte payload fields, then applies it with value zero.
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
extern "C" void BattleScene_QueuePartyCommandModeUpdate(unsigned short first, unsigned char second, unsigned char third) {
    struct Payload { unsigned short first; unsigned char second; unsigned char third; };
    struct Record { unsigned char tag; unsigned char pad[3]; Payload payload; unsigned char pad2[12]; } record;
    void* source = Network_GetCommandRecordPool();
    record.tag = 0x6c;
    Payload* p = &record.payload;
    p->first = first;
    p->second = second;
    p->third = third;
    Network_QueueOutgoingRecord(source, &record, 0);
}
