#include <globaldefs.h>
extern "C" {
struct E{int pad;E *next;};
// Original: arm9/main @ 0x02046C78; symbol: func_02046c78; size: 0x20.
int LinkedList_CountNodes(E **p){E *n=*p;int count=0;while(n){n=n->next;count++;}return count;}
}
