#include <globaldefs.h>
extern "C" {
struct E{unsigned short key;char pad[14];};struct T{E *data;int count;};
// Original: arm9/main @ 0x02099950; symbol: func_02099950; size: 0x3C.
E *Object_FindRecordByKeyInCountedArray(T *p,unsigned int key){for(int i=0;i<p->count;i++)if(p->data[i].key==key)return p->data+i;return 0;}
}
