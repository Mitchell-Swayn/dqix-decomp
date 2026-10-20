#include <globaldefs.h>
struct Table { unsigned count:12; unsigned flags:20; char* data; };
// Original: arm9/main @ 0x02079F20; symbol: func_02079f20; size: 0x7C.
extern "C" ARM void* ResourceIndex_FindEntryByExtractedKey(Table* table,int key,int (*get)(void*)) { char* base=table->data; if(!base||!get) return 0; int count=table->count; if(!count) return 0; int low=0,high=count-1; while(low<=high) { int mid=low+((high-low+1)>>1); char* entry=base+mid*8; int value=get(entry); if(value==key) return entry; if(value>key) high=mid-1; else low=mid+1; } return 0; }
