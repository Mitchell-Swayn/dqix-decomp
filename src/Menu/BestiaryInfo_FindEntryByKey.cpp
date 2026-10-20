#include <globaldefs.h>
struct Table { unsigned short count; unsigned short pad[3]; char* data; };
// Original: arm9/main @ 0x020971A8; symbol: func_020971a8; size: 0x7C.
extern "C" ARM void* BestiaryInfo_FindEntryByKey(Table* table,int key,int (*get)(void*)) { char* base=table->data; if(!base||!get) return 0; if(!table->count) return 0; int low=0,high=table->count-1; while(low<=high) { int mid=low+((high-low+1)>>1); int offset=mid*48; int value=get(base+offset); if(value==key) return base+offset; if(value>key) high=mid-1; else low=mid+1; } return 0; }
