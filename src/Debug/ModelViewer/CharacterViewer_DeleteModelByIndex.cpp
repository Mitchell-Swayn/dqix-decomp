#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Node{void* object;Node* next;};
extern "C" void CharacterViewer_DestroyModelInstanceResources(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" void CharacterViewer_RebuildMenu(void*,int);
// Original: arm9/ov015 @ 0x02191AF0; symbol: RemoveIndexedOwnedListNode; size: 0xb0.
// Removes and frees selected owned linked node, clamps selection index, then refreshes selection.
extern "C" void CharacterViewer_DeleteModelByIndex(char* p,int index){
 Node* node=*(Node**)(p+0x2c);if(!node)return;int i=0;Node* previous=0;Node* next=node->next;
 for(;i<index;i++){previous=node;node=next;next=next->next;}
 CharacterViewer_DestroyModelInstanceResources(node->object);Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,node->object);Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,node);
 if(previous)previous->next=next;else *(Node**)(p+0x2c)=next;
 unsigned count=(unsigned short)H(p,0x31e);if((int)(count-1)<=H(p,0x26c)){H(p,0x26c)=count-2;if(H(p,0x26c)<0)H(p,0x26c)=0;}
 CharacterViewer_RebuildMenu(p,0);
}
