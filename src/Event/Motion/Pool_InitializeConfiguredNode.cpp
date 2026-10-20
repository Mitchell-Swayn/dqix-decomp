#include <globaldefs.h>
ARM
extern "C" void *Queue_AppendNode(void *pool);
extern "C" void *memcpy(void *, const void *, unsigned int);
// Original: arm9/ov001 @ 0x02159004; symbol: func_ov001_02159004; size: 0x40.
extern "C" void Pool_InitializeConfiguredNode(void *pool, unsigned int a, unsigned int b, unsigned int c, unsigned int tail) {
    void *node = Queue_AppendNode(pool);
    if (node != 0) {
        *(unsigned int *)node = 5;
        memcpy((unsigned char *)node + 4, &a, 0x0C);
        *(unsigned int *)((unsigned char *)node + 0x1C) = tail;
    }
}
