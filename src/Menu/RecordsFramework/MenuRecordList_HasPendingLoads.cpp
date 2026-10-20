#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F6BC0; symbol: HasListNodeWithField1CNotTwo; size: 0x2C.
// Traverses the linked list and returns one on the first node whose word at +0x1C differs from two.
extern "C" int MenuRecordList_HasPendingLoads(void *head) {
    void *node = *(void **)head;
    while (node) {
        if (*(int *)((char *)node + 0x1c) != 2)
            return 1;
        node = *(void **)((char *)node + 0x18);
    }
    return 0;
}
