#include <globaldefs.h>
ARM

// Original: arm9/ov023 @ 0x021E1DA4; symbol: func_ov023_021e1da4; size: 0x44.
extern "C" int FindLinkedNodeIndexByHalfword8(void **head, int value) {
    void *node = *head;
    if (node == 0) return -1;
    int index = 0;
    while (node != 0) {
        if (*(short *)((char *)node + 8) == value) return index;
        index = (short)(index + 1);
        node = *(void **)node;
    }
    return -1;
}
