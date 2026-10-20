#include <globaldefs.h>
ARM
struct Object;
struct Payload { unsigned char first, second; unsigned short third, fourth; };
extern "C" void* Network_GetCommandRecordPool(void);
extern "C" void* Network_GetConnectionManager(void);
extern "C" void Network_QueueOutgoingRecord(Object*, const void*, short);
// Original: arm9/ov017 @ 0x021D0924; symbol: func_ov017_021d0924; size: 0x58.
extern "C" void Network_QueueConnectionValueRecord(unsigned char first, unsigned char second, unsigned short third, unsigned short fourth) {
    unsigned char record[20];
    Object* object = (Object*)Network_GetCommandRecordPool();
    Network_GetConnectionManager();
    Payload* payload = (Payload*)(record + 4);
    record[0] = 0x9b;
    payload->first = first;
    payload->second = second;
    payload->third = third;
    payload->fourth = fourth;
    Network_QueueOutgoingRecord(object, record, 0);
}
