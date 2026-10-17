#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Node { int kind; Node* next; char* string; };
extern "C" unsigned int data_ov000_02184264[];
extern "C" char data_ov000_02183fbc[],data_ov000_02183fc1[];
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned int,unsigned int);
extern "C" void Overlay_EnqueueLinkedNode(Node*);
// Original: arm9/ov000 @ 0x0216A4C8; symbol: func_ov000_0216a4c8; size: 0x94.
extern "C" int Script_QueuePatchedStringNode(const void* parameter) {
Node* node=(Node*)_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],12);
node->kind=0;node->next=0;
node->kind=18;
const char* string=_ZNK6Script9Parameter8ToStringEv(parameter);
node->string=_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],strlen(string)+1);
strcpy(node->string,string);
char* match=strstr(node->string,data_ov000_02183fbc);
if(match)strcpy(match,data_ov000_02183fc1);
Overlay_EnqueueLinkedNode(node);
return 1;
}
