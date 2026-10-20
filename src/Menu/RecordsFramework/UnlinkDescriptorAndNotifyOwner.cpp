#include <globaldefs.h>
ARM
struct Owner;
struct Node {
 virtual void Slot0();virtual void Slot1();virtual void Slot2();virtual void Slot3();virtual void Slot4();virtual void Slot5();virtual void NotifyUnlinked(Owner*);
 char pad[0x10];Node* previous;Node* next;
};
struct Owner {Node* head;};
// Original: arm9/ov023 @ 0x021F67EC; symbol: func_ov023_021f67ec; size: 0x58.
// Removes a descriptor from its doubly linked list, clears its links, and calls its unlink callback.
extern "C" void UnlinkDescriptorAndNotifyOwner(Owner* self,Node* node){
 if(!node)return;
 Node* previous=node->previous;Node* next=node->next;
 if(previous)previous->next=next;if(next)next->previous=previous;
 if(self->head==node)self->head=next;
 node->previous=0;node->next=0;node->NotifyUnlinked(self);
}
