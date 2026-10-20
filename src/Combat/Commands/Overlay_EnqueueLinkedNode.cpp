#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" void Util_AppendNodeToLinkedListTail(void*, void*);
// Original: arm9/ov000 @ 0x02169B78; symbol: func_ov000_02169b78; size: 0x3C.
extern "C" void Overlay_EnqueueLinkedNode(void *node) {
    void *manager = *(void **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 4);
    if (!manager) return;
    void *head = *(void **)((char *)manager + 8);
    if (!head) {
        *(void **)((char *)manager + 8) = node;
        *(void **)((char *)node + 4) = 0;
        return;
    }
    Util_AppendNodeToLinkedListTail(head, node);
}
