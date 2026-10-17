#include <globaldefs.h>
extern "C" {
struct E {int pad;short key;char rest[42];};struct T {E *data;short count;};
// Original: arm9/main @ 0x0207F6AC; symbol: func_0207f6ac; size: 0x54.
E *FindNonnegativeKeyInEntryArray(T *p,int key){if(key<0)return 0;for(short i=0;i<p->count;i++)if(p->data[i].key==key)return p->data+i;return 0;}
}
