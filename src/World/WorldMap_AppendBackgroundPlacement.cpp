#include <globaldefs.h>
struct Record{unsigned key;int index;unsigned a,b;};struct Owner{char pad[0x2c];Record*records;int count;};
extern "C" int WorldMap_FindBackgroundResourceIndex(Owner*,unsigned);
// Original: arm9/main @ 0x02027910; symbol: func_02027910; size: 0x64.
extern "C" ARM void WorldMap_AppendBackgroundPlacement(Owner*p,unsigned key,unsigned target,unsigned a,unsigned b){p->records[p->count].key=key;int index=WorldMap_FindBackgroundResourceIndex(p,target);p->records[p->count].index=index;p->records[p->count].a=a;p->records[p->count].b=b;p->count++;}
