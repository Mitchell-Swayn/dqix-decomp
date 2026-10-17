#include <globaldefs.h>
ARM
struct Pool;
struct PoolNode;
extern "C" PoolNode *FindFreePoolNodeAndClearLink(Pool *pool);
// Original: arm9/ov001 @ 0x02159F54; symbol: func_ov001_02159f54; size: 0x40.
extern "C" PoolNode *Pool_AppendAllocatedNode(Pool *pool) {
    PoolNode *node = FindFreePoolNodeAndClearLink(pool);
    if (node == 0) {
        return 0;
    }
    PoolNode *tail = *(PoolNode **)((unsigned char *)pool + 0x14);
    if (tail != 0) {
        *(PoolNode **)((unsigned char *)tail + 0x3C) = node;
    }
    *(PoolNode **)((unsigned char *)pool + 0x14) = node;
    *(PoolNode **)((unsigned char *)node + 0x3C) = 0;
    if (*(PoolNode **)((unsigned char *)pool + 0x10) == 0) {
        *(PoolNode **)((unsigned char *)pool + 0x10) = node;
    }
    return node;
}
