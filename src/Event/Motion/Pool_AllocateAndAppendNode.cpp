#include <globaldefs.h>
ARM

struct PoolNode;
struct Pool;
extern "C" PoolNode *Event_FindUnusedMotionCommand(Pool *pool);

struct PoolNode { unsigned char data[0x3c]; PoolNode *next; };
struct Pool { unsigned char data[0x40]; PoolNode *head; PoolNode *tail; };

// Original: arm9/ov001 @ 0x0215A054; symbol: func_ov001_0215a054; size: 0x40.
extern "C" PoolNode *Pool_AllocateAndAppendNode(Pool *pool) {
    PoolNode *node = Event_FindUnusedMotionCommand(pool);
    if (node == 0) return 0;
    PoolNode *tail = pool->tail;
    if (tail != 0) tail->next = node;
    pool->tail = node;
    node->next = 0;
    if (pool->head == 0) pool->head = node;
    return node;
}
