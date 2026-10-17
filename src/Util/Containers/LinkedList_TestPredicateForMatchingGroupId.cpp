#include <globaldefs.h>
ARM
struct Node {unsigned short id;char pad[18];Node* next;};
struct Group {char pad[12];Node* first;};
struct Output {char pad[48];unsigned value;};
extern "C" Group* FindKeyedGroupWhoseItemsPassPredicate(void*,int,Output*);
extern "C" int func_02061c04(void*,Node*,Output*);
// Original: arm9/main @ 0x02064B24; symbol: func_02064b24; size: 0x74.
extern "C" int LinkedList_TestPredicateForMatchingGroupId(void* owner,int group,unsigned id,Output* out) {
    Group* g=FindKeyedGroupWhoseItemsPassPredicate(owner,group,out);
    if(!g)return 0;
    out->value=0;
    for(Node* p=g->first;p;p=p->next) {
        if(p&&p->id==id&&!func_02061c04(owner,p,out))return 0;
    }
    return 1;
}
