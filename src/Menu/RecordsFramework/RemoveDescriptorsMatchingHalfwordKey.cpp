#include <globaldefs.h>
ARM
struct Node {char pad[8];unsigned short key;char padA[10];Node* previous;Node* next;};
struct Owner {Node* head;};
extern "C" void UnlinkDescriptorAndNotifyOwner(Owner*,Node*);
// Original: arm9/ov023 @ 0x021F6844; symbol: func_ov023_021f6844; size: 0x3C.
// Removes each linked descriptor whose halfword key at offset eight matches the requested value.
extern "C" void RemoveDescriptorsMatchingHalfwordKey(Owner* self,int key){
 Node* node=self->head;
 while(node){Node* next=node->next;if(node->key==key)UnlinkDescriptorAndNotifyOwner(self,node);node=next;}
}
