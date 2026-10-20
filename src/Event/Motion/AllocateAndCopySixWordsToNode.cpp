#include <globaldefs.h>
ARM

extern "C" void *Queue_AppendNode(void *pool);
extern "C" void *memcpy(void *dst, const void *src, unsigned int length);

// Original: arm9/ov001 @ 0x0215907C; symbol: func_ov001_0215907c; size: 0x48.
extern "C" void AllocateAndCopySixWordsToNode(void *pool, unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f) {
    unsigned int *node = (unsigned int *)Queue_AppendNode(pool);
    if (node == 0) return;
    node[0] = 8;
    memcpy(node + 1, &a, 12);
    memcpy(node + 4, &d, 12);
}
