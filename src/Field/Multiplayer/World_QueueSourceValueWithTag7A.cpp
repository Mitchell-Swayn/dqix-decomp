#include <globaldefs.h>
struct Object;
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object* object, const void* source, short value);
// Original: arm9/ov017 @ 0x021C8B78; symbol: func_ov017_021c8b78; size: 0x34.
extern "C" void World_QueueSourceValueWithTag7A(short value) {
    _ZN9GameState11GetInstanceEv();
    Object* object = (Object*)Network_GetCommandRecordPool();
    unsigned char source[0x14];
    source[0] = 0x7a;
    *(short*)(source + 4) = value;
    Network_QueueOutgoingRecord(object, source, 0);
}
