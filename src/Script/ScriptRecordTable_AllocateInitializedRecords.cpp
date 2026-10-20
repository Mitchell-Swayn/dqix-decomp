#include <globaldefs.h>
struct Group{void* first;char* data;unsigned short count,index;};extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);extern "C" void ScriptRecord_InitializeEntry(void*);
#pragma optimization_level 4
// Original: arm9/main @ 0x02071C64; symbol: func_02071c64; size: 0x64.
extern "C" ARM void ScriptRecordTable_AllocateInitializedRecords(Group* p,void* alloc,unsigned count){if(p->data)return;p->index=0;p->count=count;void* data=_ZN13SafeAllocator8AllocateEj(alloc,count*32);p->data=(char*)data;p->first=data;for(unsigned short i=0;i<count;++i)ScriptRecord_InitializeEntry(p->data+i*32);}
