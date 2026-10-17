#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" unsigned data_ov000_02184264[];
struct Node { unsigned type; Node *next; unsigned char value; unsigned char second; char pad[2]; char *text; };
extern "C" void Overlay_EnqueueLinkedNode(Node *);
// Original: arm9/ov000 @ 0x0216C144; symbol: func_ov000_0216c144; size: 0xA8.
extern "C" int Script_QueueOptionalStringNode(char *params, int count) {
    Node *node = (Node *)_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2], 16);
    node->type = 0;
    node->next = 0;
    node->type = 0x5b;
    node->value = _ZNK6Script9Parameter5ToIntEv(params);
    node->second = _ZNK6Script9Parameter5ToIntEv(params + 8);
    if (count >= 3) {
        const char *text = _ZNK6Script9Parameter8ToStringEv(params + 16);
        node->text = _ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2], strlen(text) + 1);
        if (node->text) strcpy(node->text, text);
    } else node->text = 0;
    Overlay_EnqueueLinkedNode(node);
    return 1;
}
