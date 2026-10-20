#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct Object;
struct PackedIdFlagAndByte { unsigned char id:7; unsigned char flag:1; unsigned char value; };
struct QueueRecord { unsigned char type; unsigned char pad[3]; PackedIdFlagAndByte payload; unsigned char remaining[14]; };
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object*, const void*, short);
// Original: arm9/ov017 @ 0x021D1014; symbol: Field_QueueMemberProfileRequest; size: 0x64.
// Queues record type 0x19 with a seven-bit ID, one flag, and one byte value.
// Other record bytes are not initialized by the original routine.
extern "C" void Field_QueueMemberProfileRequest(int id, bool flag, int value)
{
 QueueRecord record;
 Object* object = (Object*)Network_GetCommandRecordPool();
 PackedIdFlagAndByte* payload = &record.payload;
 payload->id = (unsigned char)id;
 record.type = 0x19;
 payload->flag = flag;
 payload->value = value;
 Network_QueueOutgoingRecord(object, &record, 0);
}
