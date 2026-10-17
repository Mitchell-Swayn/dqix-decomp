#include <globaldefs.h>
ARM
struct Node {unsigned char pad[20];Node* next;Node* prev;};struct Queue {unsigned char pad[12];Node* head;Node* tail;};extern Queue data_02111654;extern "C" void System_ConfigureInterruptFourAndDisplayStatusBit();
// Original: arm9/main @ 0x020C934C; symbol: func_020c934c; size: 0x38.
extern "C" void PrependDoublyLinkedGlobalNode(Node* node){Node* tail=data_02111654.tail;node->next=tail;node->prev=0;data_02111654.tail=node;if(tail){tail->prev=node;return;}data_02111654.head=node;System_ConfigureInterruptFourAndDisplayStatusBit();}
