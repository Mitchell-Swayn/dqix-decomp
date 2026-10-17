#include <globaldefs.h>
struct Node {unsigned unknown,limit,count;unsigned char disabled;char pad[0x13b];Node* next;};struct State {unsigned unknown,limit,count;unsigned char disabled;char pad[0x27];Node* children;unsigned char ignoreChildren,blocked;};
// Original: arm9/main @ 0x02057854; symbol: func_02057854; size: 0x94.
extern "C" bool TestNodeAndChildrenWithinLimits(State* self) {if(self->disabled)return false;if(self->blocked)return false;if(!self->ignoreChildren){for(Node* node=self->children;node;node=node->next){bool ready;if(node->disabled)ready=false;else {if(node->count<=node->limit)ready=true;else ready=false;}if(!ready)return false;}}return self->count<self->limit;}
