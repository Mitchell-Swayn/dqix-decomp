#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original data: arm9/main @ 0x2111654; symbol: data_02111654.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char OSInitVAlarm_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020C9384; symbol: func_020c9384; size: 0x38.
extern "C" void LinkedList_UnlinkNodeFromGlobalDoublyLinkedList(void *node) {
    if (node != 0) {
        int previous = *(int *)((char *)node + 0x14);
        int next = *(int *)((char *)node + 0x18);
        if (next != 0)
            *(int *)(next + 0x14) = previous;
        else
            *(int *)(OSInitVAlarm_UnknownRoleZeroInitializedStorage + 0x10) = previous;
        if (previous != 0)
            *(int *)(previous + 0x18) = next;
        else
            *(int *)(OSInitVAlarm_UnknownRoleZeroInitializedStorage + 0xc) = next;
    }
}
