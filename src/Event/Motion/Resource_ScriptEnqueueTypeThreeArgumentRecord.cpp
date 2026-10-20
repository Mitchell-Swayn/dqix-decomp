#include <globaldefs.h>
ARM
struct QueueNode;
extern "C" QueueNode *Queue_AppendNode(void *queue);
extern "C" void *memcpy(void *, const void *, unsigned int);
// Original: arm9/ov001 @ 0x02158F64; symbol: Resource_ScriptEnqueueTypeThreeArgumentRecord; size: 0x60.
// Allocates a queue node, tags it type 3, copies the first six arguments into its payload, and stores the final three values.
extern "C" void Resource_ScriptEnqueueTypeThreeArgumentRecord(void *queue, unsigned a1, unsigned a2, unsigned a3, unsigned a4, unsigned a5, unsigned a6, unsigned a7, unsigned a8, unsigned char a9) {
    QueueNode *node = Queue_AppendNode(queue);
    if (node == 0) return;
    *(unsigned int *)node = 3;
    memcpy((char *)node + 4, &a1, 0xc);
    memcpy((char *)node + 0x10, &a4, 0xc);
    *(unsigned int *)((char *)node + 0x1c) = a7;
    *(unsigned int *)((char *)node + 0x20) = a8;
    *(unsigned int *)((char *)node + 0x24) = (unsigned char)a9;
}
