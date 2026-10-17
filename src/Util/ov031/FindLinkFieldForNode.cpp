#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0220713C; symbol: func_ov031_0220713c; size: 0x2C.
extern "C" void **FindLinkFieldForNode(void **head, void *target) {
    void **link = head;
    void *node = *link;
    if (!node) goto not_found;
    for (;;) {
        if (node == target) return link;
        link = (void **)((char *)node + 0x7c);
        node = *link;
        if (!node) goto not_found;
    }
not_found:
    return 0;
}
