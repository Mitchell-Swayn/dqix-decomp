#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
struct Object;
extern "C" void Network_QueueOutgoingRecord(Object *, const void *, short);
// Original: arm9/ov017 @ 0x021C9CD8; symbol: World_ApplyQueuedRecordFromByte; size: 0x30.
// Builds a 0x14-byte tag-0x7d record with the input byte at +4, then applies it with value zero.
extern "C" void Network_QueueBattleContextControlByte(unsigned char value) {
    unsigned char record[0x14];
    Object *object = (Object *)Network_GetCommandRecordPool();
    record[0] = 0x7d;
    record[4] = value;
    Network_QueueOutgoingRecord(object, record, 0);
}
