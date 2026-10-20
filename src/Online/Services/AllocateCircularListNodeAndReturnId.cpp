#include <globaldefs.h>
ARM
struct Node {Node* next;Node* previous;int id;unsigned value;int state;};
typedef Node* (*Allocate)(unsigned,unsigned);
// Original data: arm9/ov031 @ 0x2290fc4; symbol: data_ov031_02290fc4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290fd8; symbol: data_ov031_02290fd8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290fdc; symbol: data_ov031_02290fdc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern Allocate HttpCreateRequestFromUrl_UnknownRoleZeroInitializedStorage_Variant2;extern Node* volatile HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage;extern volatile int AllocateCircularListNodeAndReturnId_UnknownRoleZeroInitializedStorage;}
// Original: arm9/ov031 @ 0x02240104; symbol: func_ov031_02240104; size: 0xB4.
extern "C" int AllocateCircularListNodeAndReturnId(unsigned value){
int result=-1;Node* node=HttpCreateRequestFromUrl_UnknownRoleZeroInitializedStorage_Variant2(20,4);
if(node){
Node* head=HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage;
if(!head){node->next=node;node->previous=node;HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage=node;}
else{node->next=head->next;node->previous=HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage;HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage->next->previous=node;HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage->next=node;}
node->id=AllocateCircularListNodeAndReturnId_UnknownRoleZeroInitializedStorage++;node->value=value;node->state=-1;result=node->id;
if(AllocateCircularListNodeAndReturnId_UnknownRoleZeroInitializedStorage<0)AllocateCircularListNodeAndReturnId_UnknownRoleZeroInitializedStorage=0;
}
return result;
}
