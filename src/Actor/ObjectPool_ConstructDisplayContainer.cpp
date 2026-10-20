#include <globaldefs.h>
ARM
struct Entry{unsigned char pad[0xd4];};struct State{int pad[2];Entry entries[16];};extern "C" {void ObjectPool_ConstructDisplayEntry(Entry*);void ObjectPool_ResetDisplayContainer(State*);
// Original: arm9/main @ 0x02058704; symbol: func_02058704; size: 0x38.
State* ObjectPool_ConstructDisplayContainer(State* p){Entry* end;Entry* cur=p->entries;end=p->entries+16;do{ObjectPool_ConstructDisplayEntry(cur);cur++;}while(cur<end);ObjectPool_ResetDisplayContainer(p);return p;}}
