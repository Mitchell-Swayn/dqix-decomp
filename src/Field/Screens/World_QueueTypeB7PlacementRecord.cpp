#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D38F8; symbol: World_QueueTypeB7PlacementRecord; size: 0x58.
// Called during placement updates; queues a type-0xB7 record containing four bytes and the word pointed to by the fifth argument.
extern "C" void World_QueueTypeB7PlacementRecord(unsigned char a, unsigned char b, unsigned char c, unsigned char d, const unsigned int* value) {
    void* object = Network_GetCommandRecordPool();
    unsigned char record[0x14];
    record[0] = 0xb7;
    unsigned char* payload = record + 4;
    payload[0] = a;
    payload[1] = b;
    payload[2] = c;
    payload[3] = d;
    *(unsigned int*)(payload + 4) = *value;
    Network_QueueOutgoingRecord(object, record, 0);
}
