#include <globaldefs.h>
ARM
struct SourceEntry {unsigned char* data;int pad;};
// Original data: arm9/main @ 0x210fcf4; symbol: data_0210fcf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" SourceEntry NNSSndStrmSetup_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/main @ 0x210fcb4; symbol: data_0210fcb4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char* SoundStreamDispatchNextBufferSlice_UnknownRoleZeroInitializedStorage[];
struct State {unsigned char pad[0x20];int a;int pad24;unsigned total;int period;void (*callback)(void*,int,unsigned char**,unsigned,int,int);int b;int position;int gap[3];int count;unsigned char indices[1];};
// Original: arm9/main @ 0x020BCD30; symbol: func_020bcd30; size: 0xB0.
extern "C" void SoundStream_DispatchNextBufferSlice(State* p,void* argument){
 int offset;
 unsigned width=p->total/(unsigned)p->period;
 offset=width*p->position;
 int i=0;
 if(p->count>0){do{SoundStreamDispatchNextBufferSlice_UnknownRoleZeroInitializedStorage[i]=NNSSndStrmSetup_UnknownRoleZeroInitializedStorage_Variant2[p->indices[i]].data+offset;i++;}while(i<p->count);}
 p->callback(argument,p->count,SoundStreamDispatchNextBufferSlice_UnknownRoleZeroInitializedStorage,width,p->a,p->b);
 p->position++;
 if(p->position>=p->period)p->position=0;
}
