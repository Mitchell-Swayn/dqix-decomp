#include <globaldefs.h>
ARM
struct Node { unsigned key; unsigned value; Node* prev; Node* next; };
struct Owner { unsigned pad[10]; Node* head; };
// Original: arm9/ov023 @ 0x021F6D14; symbol: func_ov023_021f6d14; size: 0x88.
extern "C" void Util_InsertNodeByAscendingKey(Owner* owner, Node* node) {
if(!node) return;
node->prev=0;node->next=0;
Node* current=owner->head;
if(!current) {owner->head=node;return;}
while(current) {
if(node->key<current->key) {
if(current->prev) current->prev->next=node;
node->next=current;
node->prev=current->prev;
current->prev=node;
if(current==owner->head) owner->head=node;
return;
}
if(!current->next) {
current->next=node;
node->prev=current;
return;
}
current=current->next;
}
}
