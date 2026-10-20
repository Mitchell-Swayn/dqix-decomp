#include <globaldefs.h>
struct Entry{unsigned id:16;unsigned result:6;unsigned arg:9;unsigned flagged:1;};struct List{Entry* entries;unsigned char count;};extern "C" char* GameState_GetSerializedProgressState();extern "C" char* _ZN15LightingManager11GetInstanceEv();extern "C" int BitArray_ReadNonnegativeIndexMask(void*,void*,unsigned);
#pragma optimization_level 4
// Original: arm9/main @ 0x0209CC3C; symbol: func_0209cc3c; size: 0x8C.
extern "C" ARM unsigned Bgm_FindConditionalZoneOverride(List* p,unsigned id){char* a=GameState_GetSerializedProgressState();char* light=_ZN15LightingManager11GetInstanceEv();for(int i=0;i<p->count;++i){Entry* entry=p->entries;if(id==entry[i].id && BitArray_ReadNonnegativeIndexMask(a,a+0x8c,entry[i].arg)){if(!entry[i].flagged||!*(int*)(light+0x98))return entry[i].result;}}return -1;}
