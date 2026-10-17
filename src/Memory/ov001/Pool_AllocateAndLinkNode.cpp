#include <globaldefs.h>
ARM
extern "C" void *FindFreePoolNodeAndClearLink(void *pool);
// Original: arm9/ov001 @ 0x02159F94; symbol: func_ov001_02159f94; size: 0x40.
extern "C" void *Pool_AllocateAndLinkNode(void *pool) {
    void *node = FindFreePoolNodeAndClearLink(pool);
    if (node == 0) return 0;
    void *current = *(void **)((unsigned char *)pool + 0x1c);
    if (current != 0) *(void **)((unsigned char *)current + 0x3c) = node;
    *(void **)((unsigned char *)pool + 0x1c) = node;
    *(void **)((unsigned char *)node + 0x3c) = 0;
    if (*(void **)((unsigned char *)pool + 0x18) == 0)
        *(void **)((unsigned char *)pool + 0x18) = node;
    return node;
}
