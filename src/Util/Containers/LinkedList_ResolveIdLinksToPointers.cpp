#include <globaldefs.h>
ARM
struct Node{Node* next;unsigned char pad[22];short id;};extern "C" {Node* BestiaryList_FindNextEligibleDisplayEntry(Node**,int);
// Original: arm9/main @ 0x02097628; symbol: func_02097628; size: 0x40.
void LinkedList_ResolveIdLinksToPointers(Node** p){Node* node;if(!(node=*p=BestiaryList_FindNextEligibleDisplayEntry(p,-1)))return;while(node){Node* next=BestiaryList_FindNextEligibleDisplayEntry(p,node->id);node->next=next;node=next;}}}
