#include <globaldefs.h>

#pragma optimization_level 2
#pragma optimize_for_size off
struct Group{unsigned count:12;unsigned other:20;char* entries;};
// Original: arm9/main @ 0x02070B0C; symbol: func_02070b0c; size: 0x60.
extern "C" ARM int VisitEvery132ByteGroupEntryWithCallback(Group* p,void(*cb)(Group*,void*)){int count;char* entry=p->entries;if(!entry||!(count=p->count)||!cb)return 0;for(int i=0;i<count;++i,entry+=0x84)cb(p,entry);return 1;}
