#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0215FEB4; symbol: func_ov000_0215feb4; size: 0x3C.
extern "C" void *Util_GetNestedListNodeAtIndex(void *base, int index, int offset) {
    if (*(unsigned char *)((unsigned char *)base + offset + 0x26) <= index) return 0;
    void *node = *(void **)((unsigned char *)base + offset * 4);
    int i = 0;
    while (i < index && node != 0) {
        node = *(void **)((unsigned char *)node + 0x20);
        i++;
    }
    return node;
}
