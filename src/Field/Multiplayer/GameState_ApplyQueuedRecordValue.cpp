#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool(void);
struct Object;
extern "C" void Network_QueueOutgoingRecord(Object* object, const void* source, short value);
// Original: arm9/ov017 @ 0x021CBBD0; symbol: func_ov017_021cbbd0; size: 0x3C.
extern "C" void GameState_ApplyQueuedRecordValue(void* input) {
    volatile unsigned char source[0x14];
    void* object = Network_GetCommandRecordPool();
    source[0] = 0x63;
    *(volatile unsigned short*)(source + 4) = *(unsigned short*)(*(char**)((char*)input + 0x8e18) + 8);
    Network_QueueOutgoingRecord((Object*)object, (const void*)source, 1);
}
