#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D0198; symbol: World_ApplyQueuedRecordFromThreeBytes; size: 0x4C.
// Builds tag 0xaa with three byte fields and a halfword payload, then applies the queued record.
extern "C" void Network_QueueFieldActionResponse(unsigned char a, unsigned char b, unsigned char c, unsigned short d) {
    struct Payload { unsigned char a,b,c,pad; unsigned short d; };
    struct Record { unsigned char tag; unsigned char pad[3]; Payload payload; unsigned char tail[8]; } record;
    void* source=Network_GetCommandRecordPool();
    record.tag=0xaa;
    Payload* p=&record.payload;
    p->a=a; p->b=b; p->c=c; p->d=d;
    Network_QueueOutgoingRecord(source,&record,0);
}
