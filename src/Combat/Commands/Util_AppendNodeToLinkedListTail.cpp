#include <globaldefs.h>
ARM
extern "C" void Util_AppendNodeToLinkedListTail(void *head, void *node);
// Original: arm9/ov000 @ 0x02169B2C; symbol: func_ov000_02169b2c; size: 0x28.
extern "C" void Util_AppendNodeToLinkedListTail(void *head, void *node) {
    void *next = *(void **)((char *)head + 4);
    if (next) {
        Util_AppendNodeToLinkedListTail(next, node);
    } else {
        *(void **)((char *)head + 4) = node;
        *(void **)((char *)node + 4) = 0;
    }
}
