#include <globaldefs.h>
ARM
struct Pool;
struct PoolNode;
extern "C" PoolNode *Pool_AppendAllocatedNode(Pool *pool);
extern "C" void *memcpy(void *, const void *, unsigned int);
// Original: arm9/ov001 @ 0x0215A44C; symbol: func_ov001_0215a44c; size: 0x34.
extern "C" void Pool_AddTypeSevenRecordFromWords(Pool *pool, unsigned int a, unsigned int b, unsigned int c) {
    PoolNode *node = Pool_AppendAllocatedNode(pool);
    if (node != 0) {
        *(unsigned int *)node = 7;
        memcpy((unsigned char *)node + 4, &a, 0xC);
    }
}
