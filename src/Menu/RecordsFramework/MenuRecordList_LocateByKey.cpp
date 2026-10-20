#include <globaldefs.h>
ARM
extern "C" unsigned short MenuRecord_GetKey(void *);
// Original: arm9/ov023 @ 0x021F6880; symbol: func_ov023_021f6880; size: 0x38.
extern "C" void *MenuRecordList_LocateByKey(void **head, unsigned short value) {
    void *node = *head;
    while (node != 0) {
        if (MenuRecord_GetKey(node) == value) return node;
        node = *(void **)((char *)node + 0x18);
    }
    return 0;
}
