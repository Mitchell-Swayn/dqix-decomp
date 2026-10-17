#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);
extern "C" void BuildStaggeredGridNeighborIndices(unsigned char*,int*);
extern "C" void LinkRecordAndNormalizePreviousHead(void**,void*);
extern "C" unsigned func_ov025_021e2494(void*);
extern "C" void* Util_UnlinkLowestPriorityNode(void**);
extern "C" unsigned Util_ContainsLinkedNode(void**,void*);
extern "C" void RemoveNodeFromNextLinkedList(void**,void*);
struct Node {unsigned char id,cost,base,heuristic,parent,blocked;unsigned short pad;Node* next;};
struct Context {Node* nodes;int count;unsigned char blocked[12],blockedCount;};
struct Neighbors {unsigned char values[6];};
// Original: arm9/ov025 @ 0x021E2148; symbol: func_ov025_021e2148; size: 0x288.
extern "C" int World_FindStaggeredGridPathReverse(Context* self,int start,int goal,unsigned char* output,int capacity) {
 if(!self->nodes) return 0;
 if(self->count<=start) return 0;
 if(self->count<=goal) return 0;
 memset(self->nodes,0,self->count*12);
 void* open=0;
 void* closed=0;
 unsigned char* blocked=self->blocked;
 for(int i=0;i<self->blockedCount;++i) {
  int index=blocked[i];
  if(self->count<=index) return 0;
  self->nodes[index].blocked=1;
 }
 Node* node=self->nodes+start;
 node->id=start;
 node->cost=0;node->base=0;node->heuristic=0;node->parent=255;node->next=0;node->blocked=0;
 LinkRecordAndNormalizePreviousHead(&open,node);
 Neighbors neighbors,temporary;
 int cell;
 for(;;) {
  if(func_ov025_021e2494(&open)) return 0;
  Node* current=(Node*)Util_UnlinkLowestPriorityNode(&open);
  if(current->id==goal) break;
  LinkRecordAndNormalizePreviousHead(&closed,current);
  cell=current->id;
  BuildStaggeredGridNeighborIndices(temporary.values,&cell);
  neighbors=temporary;
  for(int i=0;i<6;++i) {
   unsigned char id=neighbors.values[i];
   if(id==255) continue;
   Node* next=self->nodes+id;
   next->id=id;
   if(self->count<=id) return 0;
   if(next->blocked) continue;
   current->base=current->cost-current->heuristic;
   int cost=current->base+1;
   if(Util_ContainsLinkedNode(&open,next)) {
    if(cost<next->cost) {next->cost=cost;next->parent=current->id;}
   } else if(Util_ContainsLinkedNode(&closed,next)) {
    if(cost<next->cost) {
     next->cost=cost;next->parent=current->id;
     RemoveNodeFromNextLinkedList(&closed,next);
     LinkRecordAndNormalizePreviousHead(&open,next);
    }
   } else {
    next->cost=cost;next->parent=current->id;
    LinkRecordAndNormalizePreviousHead(&open,next);
   }
  }
 }
 node=self->nodes+goal;
 int written=0;
 for(;;) {
  output[written++]=node->id;
  if(capacity>written && self->count>node->parent) node=self->nodes+node->parent;
  else break;
 }
 return written;
}
