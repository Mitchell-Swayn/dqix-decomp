#include <globaldefs.h>
#pragma optimize_for_size off
struct Header { unsigned pad[3];unsigned short offset,count; }; struct Entry {unsigned key, next;};
// Original: arm9/main @ 0x020B0288; symbol: func_020b0288; size: 0x48.
 extern "C" ARM Entry* FindVariableStrideRecordByKey(Header* p,unsigned key) {unsigned short i=0;Entry* e=(Entry*)((char*)p+p->offset);unsigned count=p->count;if(i<count)do{if(e->key==key)return e;e=(Entry*)((char*)e+e->next);i=(unsigned short)(i+1);}while(i<count);return 0;}
