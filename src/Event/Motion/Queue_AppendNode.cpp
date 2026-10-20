#include <globaldefs.h>
ARM

struct QueueNode { unsigned int active; unsigned char pad[0x44]; unsigned int link; };
extern "C" QueueNode *CutsceneCamera_FindUnusedCommandRecord(void *queue);

// Original: arm9/ov001 @ 0x02158DCC; symbol: func_ov001_02158dcc; size: 0x40.
extern "C" QueueNode *Queue_AppendNode(void *queue) {
    QueueNode *node = CutsceneCamera_FindUnusedCommandRecord(queue);
    if (node == 0) return 0;
    QueueNode *tail = *(QueueNode **)((unsigned char *)queue + 0xc);
    if (tail != 0) tail->link = (unsigned int)node;
    *(QueueNode **)((unsigned char *)queue + 0xc) = node;
    node->link = 0;
    if (*(QueueNode **)((unsigned char *)queue + 8) == 0)
        *(QueueNode **)((unsigned char *)queue + 8) = node;
    return node;
}
