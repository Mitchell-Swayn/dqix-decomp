#include <globaldefs.h>
extern "C" {
struct E{short key;char pad[14];E *next;};
// Original: arm9/main @ 0x0206EF18; symbol: func_0206ef18; size: 0x28.
E *LinkedList_FindNodeBySignedKey(E **p,int key){E *n=*p;while(n){if(n->key==key)return n;n=n->next;}return 0;}
}
