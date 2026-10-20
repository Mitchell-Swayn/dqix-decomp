#include <globaldefs.h>
struct QueueNode;
struct Vector3i { unsigned x, y, z; };
extern "C" QueueNode* Queue_AppendNode(void* queue);
struct Type18QueueRecord { unsigned kind; Vector3i offset; };
// Original: arm9/ov001 @ 0x02159250; symbol: func_ov001_02159250; size: 0x40.
// Appends a type-0x12 queue record from three words and tracks its associated record on the owner.
extern "C" void CutsceneCamera_QueueFollowActorWithOffset(void* queue, void* record, Vector3i offset) {
    Type18QueueRecord* node = (Type18QueueRecord*)Queue_AppendNode(queue);
    if (node) {
        node->kind = 0x12;
        node->offset.x = offset.x;
        node->offset.y = offset.y;
        node->offset.z = offset.z;
        *(unsigned*)((unsigned char*)queue + 0xa20) = (unsigned)record;
    }
}
