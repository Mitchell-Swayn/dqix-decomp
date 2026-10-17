#include <globaldefs.h>
extern "C" {
struct E{char pad[8];short key;char pad2[14];};struct T{E *data;short count;};
// Original: arm9/main @ 0x0207F0AC; symbol: func_0207f0ac; size: 0x54.
E *FindNonnegativeKeyInCountedRecordArray(T *p,int key){if(key<0)return 0;for(short i=0;i<p->count;i++)if(p->data[i].key==key)return p->data+i;return 0;}
}
