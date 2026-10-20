#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void CharacterViewer_PushMenuHistory(void*,int);extern "C" int CharacterViewer_PopMenuHistory(void*);extern "C" void CharacterViewer_RebuildMenu(void*,int);extern "C" void CharacterViewer_DestroyModelInstanceResources(void*);extern "C" unsigned Main_UnknownRoleZeroInitializedStorage_Variant3;extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);struct Node{char* object;Node* next;};
// Original: arm9/ov015 @ 0x02192064; symbol: RemovePendingLinkedRecordAndResetSelection; size: 0xF4.
extern "C" void CharacterViewer_ConfirmOrDeletePendingModel(char* self,int mode){char* pending=P(self,52);if(!pending)return;switch(mode){case 0:CharacterViewer_PushMenuHistory(self,W(self,420));W(self,420)=39;CharacterViewer_RebuildMenu(self,0);return;case 1:{Node* node=(Node*)P(self,44);Node* prev=0;while(node){if(node->object==pending)break;prev=node;node=node->next;}if(node){char* object=node->object;Node* next=node->next;CharacterViewer_DestroyModelInstanceResources(object);Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,node->object);Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,node);if(prev)prev->next=next;else P(self,44)=(char*)next;char* selected=P(self,48);if(P(self,52)==selected){B(self,56)=B(selected,28);P(self,48)=0;}P(self,52)=0;}H(self,0x2b0)=0;W(self,420)=CharacterViewer_PopMenuHistory(self);CharacterViewer_RebuildMenu(self,0);return;}}}
