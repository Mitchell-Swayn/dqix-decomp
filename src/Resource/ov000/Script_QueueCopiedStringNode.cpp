#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" unsigned data_ov000_02184264[];
struct Node { unsigned type; Node *next; unsigned char value; char pad[3]; char *text; };
extern "C" void Overlay_EnqueueLinkedNode(Node *);
// Original: arm9/ov000 @ 0x0216AC90; symbol: func_ov000_0216ac90; size: 0x7C.
extern "C" int Script_QueueCopiedStringNode(char *params) {
    Node *node = (Node *)_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2], 16);
    node->type = 0;
    node->next = 0;
    node->type = 0x21;
    node->value = _ZNK6Script9Parameter5ToIntEv(params);
    const char *text = _ZNK6Script9Parameter8ToStringEv(params + 8);
    node->text = _ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2], strlen(text) + 1);
    strcpy(node->text, text);
    Overlay_EnqueueLinkedNode(node);
    return 1;
}
