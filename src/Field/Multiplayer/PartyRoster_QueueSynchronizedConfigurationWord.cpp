#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *);
struct Object;
extern "C" void Network_QueueOutgoingRecord(Object *, const void *, short);
// Original: arm9/ov017 @ 0x021D0D58; symbol: func_ov017_021d0d58; size: 0x44.
extern "C" void PartyRoster_QueueSynchronizedConfigurationWord(void) {
    Object *object = (Object *)Network_GetCommandRecordPool();
    void *list = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    unsigned char record[0x14];
    record[0] = 0x17;
    *(unsigned int *)(record + 4) = *(unsigned int *)((char *)list + 0x2c94);
    Network_QueueOutgoingRecord(object, record, 0);
}
