#include <globaldefs.h>
ARM
extern "C" void **FindLinkFieldForNode(void **, void *);
// Original: arm9/ov031 @ 0x02207120; symbol: func_ov031_02207120; size: 0x1C.
extern "C" void UnlinkNodeFromChain(void **head, void *node) {
    void **link = FindLinkFieldForNode(head, node);
    if (link)
        *link = *(void **)((char *)node + 0x7c);
}
