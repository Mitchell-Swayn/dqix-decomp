#include <globaldefs.h>
ARM
struct Node{unsigned char pad[20];Node* next;};extern "C" {int func_02061c04(void*,Node*,void*);
// Original: arm9/main @ 0x02064530; symbol: func_02064530; size: 0x44.
int LinkedList_TestPredicateForAllNodes(void* p,Node* node,void* q){while(node){if(!func_02061c04(p,node,q))return 0;node=node->next;}return 1;}}
