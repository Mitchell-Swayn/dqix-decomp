#include <globaldefs.h>
ARM
struct Node {Node* next;Node* prev;unsigned a;char* object;};
extern "C" Node* Resource_FindCircularNodeByKey();
// Original data: arm9/ov031 @ 0x2290fdc; symbol: data_ov031_02290fdc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Node* HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2290fc8; symbol: data_ov031_02290fc8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void(*HttpDestroyRequest_UnknownRoleZeroInitializedStorage)(void*);
extern "C" int Http_DestroyRequest(void*);
// Original: arm9/ov031 @ 0x02240210; symbol: Resource_RemoveReadyCircularNodeAndNotifyOwner; size: 0xa0.
// Unlinks ready circular node, dispatches object callbacks, frees node and notifies saved owner with event8.
extern "C" bool Resource_RemoveReadyCircularNodeAndNotifyOwner() {
 bool result=false;Node* node=Resource_FindCircularNodeByKey();if(node){
 if(HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage!=HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage->next){node->next->prev=node->prev;node->prev->next=node->next;if(HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage==node)HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage=node->prev;}else HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage=0;
 char* object=node->object;void(*notify)(int,unsigned,unsigned)=*(void(**)(int,unsigned,unsigned))(object+0x3c);unsigned a=*(unsigned*)(object+0x30),b=*(unsigned*)(object+0x2c);
 Http_DestroyRequest(object);HttpDestroyRequest_UnknownRoleZeroInitializedStorage(node);notify(8,a,b);result=true;
 }return result;
}
