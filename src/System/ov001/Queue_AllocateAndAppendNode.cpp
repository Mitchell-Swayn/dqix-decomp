#include <globaldefs.h>
ARM
struct QueueNode;
struct Queue;
extern "C" QueueNode* FindFreeQueueNodeAndClearLink(Queue*);
struct QueueNode { unsigned char pad[0x48]; QueueNode* next; };
struct Queue { unsigned char pad[0x20]; QueueNode* tail; QueueNode* head; };
// Original: arm9/ov001 @ 0x02158E4C; symbol: func_ov001_02158e4c; size: 0x40.
extern "C" QueueNode* Queue_AllocateAndAppendNode(Queue* queue) {
    QueueNode* node = FindFreeQueueNodeAndClearLink(queue);
    if (node == 0) return 0;
    if (queue->head != 0) queue->head->next = node;
    queue->head = node;
    node->next = 0;
    if (queue->tail == 0) queue->tail = node;
    return node;
}
