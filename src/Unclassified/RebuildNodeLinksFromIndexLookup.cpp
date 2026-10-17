#include <globaldefs.h>
struct Node{unsigned char pad[0x18];short index;short padding;Node* next;};extern "C" Node* FindFlaggedRecordWithSmallestValueAboveThreshold(Node**,int);
// Original: arm9/main @ 0x0207214C; symbol: func_0207214c; size: 0x40.
extern "C" ARM void RebuildNodeLinksFromIndexLookup(Node** head){*head=FindFlaggedRecordWithSmallestValueAboveThreshold(head,-1);Node* node=*head;if(node){while(node){Node* next=FindFlaggedRecordWithSmallestValueAboveThreshold(head,node->index);node->next=next;node=next;}}}
