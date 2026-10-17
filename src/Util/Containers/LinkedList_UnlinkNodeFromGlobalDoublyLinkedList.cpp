#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" unsigned char data_02111654[];
// Original: arm9/main @ 0x020C9384; symbol: func_020c9384; size: 0x38.
extern "C" void LinkedList_UnlinkNodeFromGlobalDoublyLinkedList(void *node) {
    if (node != 0) {
        int previous = *(int *)((char *)node + 0x14);
        int next = *(int *)((char *)node + 0x18);
        if (next != 0)
            *(int *)(next + 0x14) = previous;
        else
            *(int *)(data_02111654 + 0x10) = previous;
        if (previous != 0)
            *(int *)(previous + 0x18) = next;
        else
            *(int *)(data_02111654 + 0xc) = next;
    }
}
