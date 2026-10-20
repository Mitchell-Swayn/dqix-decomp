#include <globaldefs.h>
extern "C" {
struct E{int pad;E *next;};
// Original: arm9/main @ 0x02046B38; symbol: func_02046b38; size: 0x28.
int LinkedList_ContainsNodeByIdentity(E **p,E *key){for(E *n=*p;n;n=n->next)if(n==key)return 1;return 0;}
}
