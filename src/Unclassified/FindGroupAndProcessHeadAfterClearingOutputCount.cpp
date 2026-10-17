#include <globaldefs.h>
ARM
struct Node;struct Table{int pad[3];Node* head;};struct State{int pad[12];int count;};extern "C" {Table* FindKeyedGroupWhoseItemsPassPredicate(void*,int,State*);int LinkedList_TestPredicateForAllNodes(void*,Node*,State*);
// Original: arm9/main @ 0x020649B0; symbol: func_020649b0; size: 0x44.
bool FindGroupAndProcessHeadAfterClearingOutputCount(void* p,int x,State* q){Table* table=FindKeyedGroupWhoseItemsPassPredicate(p,x,q);if(!table)return false;q->count=0;return LinkedList_TestPredicateForAllNodes(p,table->head,q)!=0;}}
