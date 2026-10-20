#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021CDD70; symbol: World_QueueType6BHalfwordsAndByteRecord; size: 0x64.
// Builds a type-0x6B queued record from six halfwords and one byte, then applies it to the global object with source value zero.
extern "C" void World_QueueType6BHalfwordsAndByteRecord(unsigned short a, unsigned short b, unsigned short c, unsigned short d, unsigned short e, unsigned short f, unsigned char g) {
    void* object = Network_GetCommandRecordPool();
    unsigned char record[0x14];
    record[0] = 0x6b;
    unsigned char* payload = record + 4;
    *(unsigned short*)(payload) = a;
    *(unsigned short*)(payload + 2) = b;
    *(unsigned short*)(payload + 4) = c;
    *(unsigned short*)(payload + 6) = d;
    *(unsigned short*)(payload + 10) = e;
    *(unsigned short*)(payload + 8) = f;
    payload[12] = g;
    Network_QueueOutgoingRecord(object, record, 0);
}
