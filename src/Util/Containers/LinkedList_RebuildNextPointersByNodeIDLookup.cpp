#include <globaldefs.h>
ARM
struct Node{Node* next;unsigned char pad[10];short id;};extern "C" {Node* Object_FindLowestEnabledKeyGreaterThanTarget(Node**,int);
// Original: arm9/main @ 0x020976E0; symbol: func_020976e0; size: 0x40.
void LinkedList_RebuildNextPointersByNodeIDLookup(Node** p){Node* node;if(!(node=*p=Object_FindLowestEnabledKeyGreaterThanTarget(p,-1)))return;while(node){Node* next=Object_FindLowestEnabledKeyGreaterThanTarget(p,node->id);node->next=next;node=next;}}}
