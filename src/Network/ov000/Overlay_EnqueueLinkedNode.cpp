#include <globaldefs.h>
ARM
extern "C" char data_ov000_02184264[];
extern "C" void Util_AppendNodeToLinkedListTail(void*, void*);
// Original: arm9/ov000 @ 0x02169B78; symbol: func_ov000_02169b78; size: 0x3C.
extern "C" void Overlay_EnqueueLinkedNode(void *node) {
    void *manager = *(void **)(data_ov000_02184264 + 4);
    if (!manager) return;
    void *head = *(void **)((char *)manager + 8);
    if (!head) {
        *(void **)((char *)manager + 8) = node;
        *(void **)((char *)node + 4) = 0;
        return;
    }
    Util_AppendNodeToLinkedListTail(head, node);
}
