#include <globaldefs.h>


struct Node { Node* next; unsigned char pad[15]; unsigned char low:1; unsigned char selected:1; unsigned char high:6; };
// Original: arm9/main @ 0x02097844; symbol: func_02097844; size: 0xB8.
extern "C" ARM void LinkedList_FilterGroupsContainingByte13Bit1SelectedNode(Node** head,int size) { if(size<=0)return; int count=0,selected=0,groups=0; Node* start=*head; Node* tail=0; Node* firstTail=0; Node* current=*head; while(current) { ++count; if(current->selected)++selected; Node* last=current; current=current->next; if(count==size || !current) { if(selected>0) { ++groups; if(tail)tail->next=start; else *head=start; tail=last; } count=0; selected=0; start=current; if(!firstTail)firstTail=last; } } if(!groups) { if(firstTail)firstTail->next=0; } else { if(tail)tail->next=0; } }
