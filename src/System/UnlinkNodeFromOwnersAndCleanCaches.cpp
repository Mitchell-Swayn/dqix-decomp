#include <globaldefs.h>
#include <System/Cache.h>
struct Node {unsigned first;Node* next;};
struct Owner {char pad[0x18];Node* first;};
struct Link {Owner* owner;Node* next;};
struct Object {char pad[0x18];Link links[4];};
extern "C" void Object_InvokeLockMutex();
extern "C" void SoundCommand_UnlockMutex();
// Original: arm9/main @ 0x020D2C00; symbol: func_020d2c00; size: 0x98.
extern "C" void UnlinkNodeFromOwnersAndCleanCaches(Object* p) {Object_InvokeLockMutex();Node* target=(Node*)p->links;int i=0;do{Owner* owner=p->links[i].owner;if(owner){Node* node=owner->first;if(target==node){owner->first=p->links[i].next;CleanCacheRange(owner,0x3c);}else{if(node)do{Node* next=node->next;if(target!=next)node=next;else break;}while(node);node->next=p->links[i].next;CleanCacheRange(node,8);}}i++;target=(Node*)((char*)target+8);}while(i<4);SoundCommand_UnlockMutex();}
