#include <globaldefs.h>
ARM
#include <System/Memory.h>
struct Object;
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object* object,const void* source,short value);
#pragma pack(1)
struct ChunkPayload { char data[13]; unsigned char packed; unsigned short value; };
#pragma pack()
struct ChunkRecord { unsigned char type; char pad[3]; ChunkPayload payload; };
// Original: arm9/ov017 @ 0x021D3D40; symbol: func_ov017_021d3d40; size: 0x8C.
extern "C" void GameState_QueueThirteenByteChunk(const void *data, unsigned length, unsigned flag, unsigned mode, int value) {
    Object *object = (Object *)Network_GetCommandRecordPool();
    ChunkRecord record;
    ChunkPayload *payload = &record.payload;
    record.type = 0xb9;
    payload->packed = (payload->packed & ~0x70) | ((mode & 7) << 4);
    payload->packed = (payload->packed & ~0x80) | ((flag & 1) << 7);
    payload->packed = (payload->packed & ~0x0f) | (length & 15);
    payload->value = value;
    MI_CpuCopy8(data, payload->data, length);
    Network_QueueOutgoingRecord(object, &record, 0);
}
