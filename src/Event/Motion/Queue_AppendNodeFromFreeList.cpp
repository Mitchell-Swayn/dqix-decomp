#include <globaldefs.h>
struct QueueNode; struct Queue;
ARM
extern "C" QueueNode* CutsceneCamera_FindUnusedCommandRecord(Queue* queue);
// Original: arm9/ov001 @ 0x02158E0C; symbol: func_ov001_02158e0c; size: 0x40.
extern "C" QueueNode* Queue_AppendNodeFromFreeList(Queue* queue) {
    QueueNode* node = CutsceneCamera_FindUnusedCommandRecord(queue);
    if (node == 0) return 0;
    QueueNode* tail = *(QueueNode**)((char*)queue + 0x14);
    if (tail != 0) *(QueueNode**)((char*)tail + 0x48) = node;
    *(QueueNode**)((char*)queue + 0x14) = node;
    *(QueueNode**)((char*)node + 0x48) = 0;
    if (*(QueueNode**)((char*)queue + 0x10) == 0) *(QueueNode**)((char*)queue + 0x10) = node;
    return node;
}
