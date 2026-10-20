#include <globaldefs.h>
ARM
struct Pool;
struct PoolNode;
extern "C" PoolNode *Pool_AllocateAndAppendNode(Pool *pool);
// Original: arm9/ov001 @ 0x0215A4E8; symbol: func_ov001_0215a4e8; size: 0x28.
extern "C" PoolNode *Memory_AllocateAndInitializePoolNode(Pool *pool, int value1, int value2) {
    PoolNode *node = Pool_AllocateAndAppendNode(pool);
    if (node) {
        *(int *)node = 0x13;
        *(int *)((char *)node + 0x10) = value1;
        *(int *)((char *)node + 0x14) = value2;
    }
    return node;
}
