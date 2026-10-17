#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
struct Object;
extern "C" void* ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(Object* object,const void* source,short value);
struct Record { unsigned char type; char pad[3]; short id; char pad6; unsigned char mode : 4; signed char flags : 4; short rotation; short y; int x; int z; };
// Original: arm9/ov017 @ 0x021C9400; symbol: func_ov017_021c9400; size: 0x9C.
extern "C" void GameState_QueueObjectTransform(unsigned id, int mode, int unused, Vector3fix position, Vector3fix rotation, unsigned flags) {
    Object *queue = (Object *)ReadGlobalAt02100044();
    Record record;
    record.type = 0x85;
    record.id = id;
    record.mode = (unsigned char)mode;
    record.flags = (signed char)flags;
    record.x = position.x;
    record.y = position.y >> 4;
    record.z = position.z;
    record.rotation = rotation.y;
    MoveQueuedRecordAndApplySourceValue(queue, &record, 0);
}
