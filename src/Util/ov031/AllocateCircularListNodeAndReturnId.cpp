#include <globaldefs.h>
ARM
struct Node {Node* next;Node* previous;int id;unsigned value;int state;};
typedef Node* (*Allocate)(unsigned,unsigned);
extern "C" {extern Allocate data_ov031_02290fc4;extern Node* volatile data_ov031_02290fdc;extern volatile int data_ov031_02290fd8;}
// Original: arm9/ov031 @ 0x02240104; symbol: func_ov031_02240104; size: 0xB4.
extern "C" int AllocateCircularListNodeAndReturnId(unsigned value){
int result=-1;Node* node=data_ov031_02290fc4(20,4);
if(node){
Node* head=data_ov031_02290fdc;
if(!head){node->next=node;node->previous=node;data_ov031_02290fdc=node;}
else{node->next=head->next;node->previous=data_ov031_02290fdc;data_ov031_02290fdc->next->previous=node;data_ov031_02290fdc->next=node;}
node->id=data_ov031_02290fd8++;node->value=value;node->state=-1;result=node->id;
if(data_ov031_02290fd8<0)data_ov031_02290fd8=0;
}
return result;
}
