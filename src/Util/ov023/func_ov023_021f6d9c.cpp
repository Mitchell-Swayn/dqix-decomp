#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F6D9C; symbol: func_ov023_021f6d9c; size: 0x3C.
extern "C" void func_ov023_021f6d9c(void *list, void *node) {
    if (node == 0) return;
    if (node == *(void **)((char *)list + 0x28))
        *(void **)((char *)list + 0x28) = *(void **)((char *)node + 0x0c);
    void *prev = *(void **)((char *)node + 8);
    if (prev != 0) *(void **)((char *)prev + 0x0c) = *(void **)((char *)node + 0x0c);
    void *next = *(void **)((char *)node + 0x0c);
    if (next != 0) *(void **)((char *)next + 8) = *(void **)((char *)node + 8);
}
