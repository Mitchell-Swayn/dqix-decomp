#include <globaldefs.h>
struct Item {char pad[12];Item* next;};
struct Group {char pad[6];unsigned char key;char pad7;Item* items;unsigned unused;Group* next;Group* searchNext;};
struct Object {char pad[0x47c];Group* groups;char pad480[18];unsigned char flag;};
extern "C" bool func_0205faf4(Object*,Item*,unsigned);
// Original: arm9/main @ 0x02064490; symbol: func_02064490; size: 0xA0.
extern "C" Group* FindKeyedGroupWhoseItemsPassPredicate(Object* p,unsigned key,unsigned arg) {Group* group=p->groups;while(group){if(group->key==key)break;group=group->searchNext;}if(!group)return 0;p->flag=0;bool okay=true;while(group){for(Item* i=group->items;i;i=i->next){if(!func_0205faf4(p,i,arg)){okay=false;break;}okay=true;}if(okay)return group;group=group->next;}return 0;}
