#include <globaldefs.h>
ARM
struct Object;
struct Payload { unsigned char a, b, c, d, e, f; unsigned short pad; unsigned word; };
extern "C" void* Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(Object*, const void*, short);
// Original: arm9/ov017 @ 0x021D1874; symbol: func_ov017_021d1874; size: 0x64.
extern "C" void ZoneFeatures_QueueTriggerSynchronization(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char f, unsigned word) {
    unsigned char record[20];
    Object* object = (Object*)Network_GetCommandRecordPool();
    Payload* payload = (Payload*)(record + 4);
    record[0] = 0xae;
    payload->a = a;
    payload->b = b;
    payload->c = c;
    payload->d = d;
    payload->e = e;
    payload->f = f;
    payload->word = word;
    Network_QueueOutgoingRecord(object, record, 0);
}
