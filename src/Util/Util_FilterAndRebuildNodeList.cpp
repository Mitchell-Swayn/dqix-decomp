#include <globaldefs.h>
ARM
struct FilterNode { FilterNode* next; char pad[0xe]; signed char group; unsigned char selected:1,other:7; unsigned char* values; unsigned char count; char tail[7]; };
struct FilterList { FilterNode* head; unsigned count:12,reserved:20; FilterNode* nodes; };
extern "C" {
void LinkedList_ResolveIdLinksToPointers(FilterNode**);
void LinkedList_RebuildNextPointersByNodeIDLookup(FilterNode**);
void LinkedList_FilterGroupsContainingByte13Bit1SelectedNode(FilterNode**,int);
}
// Original: arm9/main @ 0x020974B0; symbol: func_020974b0; size: 0x178.
extern "C" FilterNode* Util_FilterAndRebuildNodeList(FilterList* p,int group,int value,int mode,short size,short* count) {
 unsigned short n=p->count;
 FilterNode* nodes=p->nodes;
 p->head=0;
 for(short i=0;i<n;i++) { *(unsigned*)&nodes[i]=0; nodes[i].selected=1; }
 if(group>=0) {
  for(short i=0;i<n;i++) { FilterNode* node=&nodes[i]; node->selected=node->group==group; }
 }
 if(value>=0) {
  unsigned char key=value;
  for(short i=0;i<n;i++) {
   FilterNode* node=&nodes[i];
   node->selected=0;
   for(unsigned char j=0;j<node->count;j++) {
    if(key==node->values[j]) { node->selected=1; break; }
   }
  }
 }
 if(!mode) LinkedList_ResolveIdLinksToPointers((FilterNode**)p);
 else LinkedList_RebuildNextPointersByNodeIDLookup((FilterNode**)p);
 *count=0;
 for(FilterNode* node=p->head;node;node=node->next) ++*count;
 LinkedList_FilterGroupsContainingByte13Bit1SelectedNode((FilterNode**)p,size);
 return p->head;
}
