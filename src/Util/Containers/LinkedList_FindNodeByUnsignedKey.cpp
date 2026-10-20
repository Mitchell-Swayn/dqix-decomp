#include <globaldefs.h>
extern "C" {
struct E{unsigned char key;char pad[103];E *next;};
// Original: arm9/main @ 0x0206DB20; symbol: func_0206db20; size: 0x28.
E *LinkedList_FindNodeByUnsignedKey(E **p,unsigned int key){E *n=*p;while(n){if(n->key==key)return n;n=n->next;}return 0;}
}
