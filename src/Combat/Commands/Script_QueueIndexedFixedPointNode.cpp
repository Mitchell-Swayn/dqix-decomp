#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
struct Node { unsigned type; Node *next; void *data; short index; short value; unsigned char flag; char pad[3]; };
extern "C" void Overlay_EnqueueLinkedNode(Node *);
// Original: arm9/ov000 @ 0x0216A95C; symbol: func_ov000_0216a95c; size: 0x80.
extern "C" int Script_QueueIndexedFixedPointNode(char *params) {
    Node *node = (Node *)_ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2], 20);
    int index = _ZNK6Script9Parameter5ToIntEv(params);
    int value = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(params + 8));
    node->type = 0;
    node->next = 0;
    node->type = 0x19;
    node->value = value;
    node->index = index + 100;
    node->flag = 0;
    node->data = 0;
    Overlay_EnqueueLinkedNode(node);
    return 1;
}
