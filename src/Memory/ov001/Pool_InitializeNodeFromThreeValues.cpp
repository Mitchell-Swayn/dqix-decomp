#include <globaldefs.h>
ARM
extern "C" void *Pool_AppendFreeNode(void *pool);
extern "C" void *memcpy(void *, const void *, unsigned int);
// Original: arm9/ov001 @ 0x0215A330; symbol: func_ov001_0215a330; size: 0x34.
extern "C" void Pool_InitializeNodeFromThreeValues(void *pool, unsigned int a, unsigned int b, unsigned int c) {
    void *node = Pool_AppendFreeNode(pool);
    if (node != 0) {
        *(unsigned int *)node = 1;
        memcpy((unsigned char *)node + 4, &a, 0x0C);
    }
}
