#include <globaldefs.h>
ARM
struct Node { unsigned pad[3]; unsigned lowC:20;unsigned kind:8;unsigned highC:4; unsigned low10:21;unsigned enabled:1;unsigned selected:1;unsigned category:8;unsigned high10:1;unsigned pad14;short index;short pad1a;Node* next;};
struct List {Node*head;Node*nodes;unsigned short pad,count;};
extern "C" void ScriptRecordTable_LinkEligibleByPrimaryOrder(Node**);
extern "C" void LinkedList_ResolveHalfwordLinksToPointers(char**);
extern "C" void LinkedList_FilterGroupsContainingWord10Bit22SelectedNode(Node**,int);
// Original: arm9/main @ 0x02071FFC; symbol: func_02071ffc; size: 0x150.
extern "C" Node* LinkedList_SelectAndRebuildNodes(List* self,int kind,int category,int mode,short groupSize,short* count) {
 unsigned short n=self->count;Node* nodes=self->nodes;
 self->head=0;
 for(unsigned short i=0;i<n;i++){Node* node=&nodes[i];node->next=0;node->enabled=1;}
 if(kind>=0)for(unsigned short i=0;i<n;i++) nodes[i].enabled=(kind==nodes[i].kind);
 if(category>=0)for(unsigned short i=0;i<n;i++) nodes[i].enabled=(category==nodes[i].category);
 if(mode==0) ScriptRecordTable_LinkEligibleByPrimaryOrder(&self->head);
 else LinkedList_ResolveHalfwordLinksToPointers((char**)&self->head);
 *count=0;
 Node* node=self->head;
 while(node){++*count;node=node->next;}
 LinkedList_FilterGroupsContainingWord10Bit22SelectedNode(&self->head,groupSize);
 return self->head;
}
