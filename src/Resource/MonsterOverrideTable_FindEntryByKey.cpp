#include <globaldefs.h>
struct SearchTable { unsigned count:12; unsigned rest:20; char* data; };
// Original: arm9/main @ 0x020A9288; symbol: func_020a9288; size: 0x7C.
extern "C" void* MonsterOverrideTable_FindEntryByKey(SearchTable* table,int key,int (*getKey)(void*)) {
char* data=table->data; if(!data || !getKey) return 0;
if(!table->count)return 0; int lo; int hi=table->count-1; lo=0;
while(lo<=hi) { int mid=lo+((hi-lo+1)>>1); char* item=data+mid*64; int value=getKey(item); if(value==key)return item; if(value>key)hi=mid-1;else lo=mid+1; } return 0;
}
