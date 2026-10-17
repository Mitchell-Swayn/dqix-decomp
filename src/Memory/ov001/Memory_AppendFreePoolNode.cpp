#include <globaldefs.h>
ARM
struct PoolNode;
struct Pool;
extern "C" PoolNode* FindFreePoolNodeAndClearLink(Pool* pool);
struct PoolNode { unsigned char pad[0x3C]; PoolNode* next; };
struct Pool { unsigned char pad[0x38]; PoolNode* head; PoolNode* tail; };
// Original: arm9/ov001 @ 0x0215A014; symbol: func_ov001_0215a014; size: 0x40.
extern "C" PoolNode* Memory_AppendFreePoolNode(Pool* pool) {
    PoolNode* node = FindFreePoolNodeAndClearLink(pool);
    if (node == 0) return 0;
    PoolNode* tail = pool->tail;
    if (tail != 0) tail->next = node;
    pool->tail = node;
    node->next = 0;
    if (pool->head == 0) pool->head = node;
    return node;
}
