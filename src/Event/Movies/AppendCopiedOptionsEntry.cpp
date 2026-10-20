#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
struct Entry {char payload[24];Entry* next;};struct List {Entry* head;unsigned count,allocator;};
// Original: arm9/ov016 @ 0x0218E020; symbol: func_ov016_0218e020; size: 0x78.
// Appends an allocated copy of a 28-byte options record to a linked list.
extern "C" void AppendCopiedOptionsEntry(List* list,const Entry* input) {
 if(!list->allocator)return;
 Entry* node=(Entry*)_ZN13SafeAllocator8AllocateEj(list->allocator,28);if(!node)return;
 memcpy(node,input,28);node->next=0;
 Entry* tail=list->head;
 if(tail){while(tail->next)tail=tail->next;tail->next=node;}else list->head=node;
 ++list->count;
}
