#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Node { int kind; Node* next; char* string; };
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned int CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" char Script_QueuePatchedStringNode_TextPac[],Script_QueuePatchedStringNode_TextChr[];
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned int,unsigned int);
extern "C" void Overlay_EnqueueLinkedNode(Node*);
// Original: arm9/ov000 @ 0x0216A4C8; symbol: func_ov000_0216a4c8; size: 0x94.
extern "C" int Script_QueuePatchedStringNode(const void* parameter) {
Node* node=(Node*)_ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2],12);
node->kind=0;node->next=0;
node->kind=18;
const char* string=_ZNK6Script9Parameter8ToStringEv(parameter);
node->string=_ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2],strlen(string)+1);
strcpy(node->string,string);
char* match=strstr(node->string,Script_QueuePatchedStringNode_TextPac);
if(match)strcpy(match,Script_QueuePatchedStringNode_TextChr);
Overlay_EnqueueLinkedNode(node);
return 1;
}
