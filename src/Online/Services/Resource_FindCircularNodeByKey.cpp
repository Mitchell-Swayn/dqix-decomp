#include <globaldefs.h>
ARM
struct CircularNode { CircularNode* previous; CircularNode* next; void* key; };
// Original data: arm9/ov031 @ 0x2290fdc; symbol: data_ov031_02290fdc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" CircularNode* HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022401B8; symbol: func_ov031_022401b8; size: 0x58.
// Finds the first key in the global circular node list, stopping when it returns to the head.
extern "C" CircularNode* Resource_FindCircularNodeByKey(void* key) {
 CircularNode* found=0;
 CircularNode* head=HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage;
 if(head) {
 if(head->key==key)found=head;
 else {
 CircularNode* node=head->next;
 if(node!=head)do {
 if(node->key==key){found=node;break;}
 node=node->next;
 }while(node!=head);
 }
 }
 return found;
}
