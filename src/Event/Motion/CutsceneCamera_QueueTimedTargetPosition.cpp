#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void *memcpy(void *, const void *, unsigned int);
struct QueueNode { unsigned int active; unsigned char pad[0x44]; unsigned int link; };
extern "C" QueueNode *Queue_AppendNode(void *queue);

// Original: arm9/ov001 @ 0x02158FC4; symbol: func_ov001_02158fc4; size: 0x40.
extern "C" void CutsceneCamera_QueueTimedTargetPosition(void *queue, unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    QueueNode *node = Queue_AppendNode(queue);
    if (node != 0) {
        node->active = 4;
        memcpy((unsigned char *)node + 0x10, &a, 0xc);
        *(unsigned int *)((unsigned char *)node + 0x1c) = d;
    }
}
