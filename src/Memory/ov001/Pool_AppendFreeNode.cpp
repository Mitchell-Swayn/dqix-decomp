#include <globaldefs.h>
ARM
extern "C" void *FindFreePoolNodeAndClearLink(void *pool);
// Original: arm9/ov001 @ 0x02159F14; symbol: func_ov001_02159f14; size: 0x40.
extern "C" void *Pool_AppendFreeNode(void *pool) {
    void *node = FindFreePoolNodeAndClearLink(pool);
    if (node == 0) return 0;
    void *tail = *(void **)((unsigned char *)pool + 0x0C);
    if (tail != 0) *(void **)((unsigned char *)tail + 0x3C) = node;
    *(void **)((unsigned char *)pool + 0x0C) = node;
    *(void **)((unsigned char *)node + 0x3C) = 0;
    if (*(void **)((unsigned char *)pool + 8) == 0) *(void **)((unsigned char *)pool + 8) = node;
    return node;
}
