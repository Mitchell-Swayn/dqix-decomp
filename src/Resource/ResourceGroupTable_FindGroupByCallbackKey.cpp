#include <globaldefs.h>
struct Entry { unsigned a,b; }; struct Table { unsigned short count; unsigned short pad; unsigned unknown; Entry* entries; };
// Original: arm9/main @ 0x020DFB48; symbol: func_020dfb48; size: 0x78.
 extern "C" Entry* ResourceGroupTable_FindGroupByCallbackKey(Table* p,int key,int (*get)(Entry*)) { Entry* entries=p->entries; if(!entries || !get)return 0; if(!p->count)return 0; int low=0,high=p->count-1; while(low<=high) { int mid=low+((high-low+1)>>1); Entry* e=entries+mid; int v=get(e); if(v==key)return e; if(v>key)high=mid-1;else low=mid+1; } return 0; }
