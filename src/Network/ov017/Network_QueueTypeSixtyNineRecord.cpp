#include <globaldefs.h>
ARM
struct Payload { short first; short second; unsigned char third; unsigned char fourth; };
struct Record { unsigned char type; unsigned char padding[3]; Payload payload; unsigned char tail[8]; };
extern "C" void* ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
// Original: arm9/ov017 @ 0x021CD4C8; symbol: func_ov017_021cd4c8; size: 0x48.
extern "C" void Network_QueueTypeSixtyNineRecord(short first, short second, unsigned char third) {
    void *object = ReadGlobalAt02100044();
    Record record;
    record.type = 0x69;
    Payload *payload = &record.payload;
    payload->first = first;
    payload->second = second;
    payload->third = third;
    payload->fourth = 0;
    MoveQueuedRecordAndApplySourceValue(object, &record, 0);
}
