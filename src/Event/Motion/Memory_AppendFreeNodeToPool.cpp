#include <globaldefs.h>
ARM
struct PoolNode { unsigned char pad[0x3c]; PoolNode* next; };
struct Pool { unsigned char pad[0x30]; PoolNode* head; PoolNode* tail; };
extern "C" PoolNode* Event_FindUnusedMotionCommand(Pool* pool);
// Original: arm9/ov001 @ 0x02159FD4; symbol: func_ov001_02159fd4; size: 0x40.
extern "C" PoolNode* Memory_AppendFreeNodeToPool(Pool* pool) {
    PoolNode* node = Event_FindUnusedMotionCommand(pool);
    if (!node) return 0;
    if (pool->tail) pool->tail->next = node;
    pool->tail = node;
    node->next = 0;
    if (!pool->head) pool->head = node;
    return node;
}
