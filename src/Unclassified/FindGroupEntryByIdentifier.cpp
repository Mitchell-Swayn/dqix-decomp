#include <globaldefs.h>
struct Entry { unsigned short id:12,flags:4; unsigned short value; }; struct Group { unsigned short id,count; unsigned unknown; Entry entries[1]; }; extern "C" Group* FindThirtyTwoByteRecordByHalfwordKey(void*,int);
// Original: arm9/main @ 0x0209BE84; symbol: func_0209be84; size: 0x54.
 extern "C" Entry* FindGroupEntryByIdentifier(void* p,unsigned key,int group) { Group* g=FindThirtyTwoByteRecordByHalfwordKey(p,group); if(g) { int i=0; for(;i<g->count;++i) { if(key==g->entries[i].id)return g->entries+i; } } return 0; }
