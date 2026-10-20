#include <globaldefs.h>
ARM
extern "C" int _ffix(unsigned);
extern "C" unsigned _fmul(unsigned,unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" unsigned _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
struct Param { unsigned type,value; };
struct Entry { int type; int other; short a,b,c,d,e,f,g; };
// Original: arm9/ov000 @ 0x0216A018; symbol: func_ov000_0216a018; size: 0x18C.
extern "C" int Script_AllocateTypeSevenHalfwordEntry(Param* params,int count) {
 Entry* entry=(Entry*)_ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2],24);
 entry->type=7;
 if(count==0) {
 entry->a=0;entry->b=-1;entry->c=-1;entry->d=0;entry->f=0;entry->e=0;entry->g=0;
 } else if(count==1 && params->type==2) {
 entry->a=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(params)));
 entry->b=-1;entry->c=-1;entry->d=0;entry->f=0;entry->e=0;entry->g=0;
 } else {
 entry->a=0;
 entry->b=_ZNK6Script9Parameter5ToIntEv(params++);
 entry->c=_ZNK6Script9Parameter5ToIntEv(params++);
 if(count<3) entry->d=0;else entry->d=_ZNK6Script9Parameter5ToIntEv(params++);
 if(count<4) entry->f=0;else entry->f=_ZNK6Script9Parameter5ToIntEv(params++);
 if(count<5) entry->e=0;else entry->e=_ZNK6Script9Parameter5ToIntEv(params++);
 entry->g=count<6?0:_ZNK6Script9Parameter5ToIntEv(params);
 if(entry->b>=0 && entry->b<100) entry->b+=100;
 if(entry->c>=0 && entry->c<100) entry->c+=100;
 }
 Overlay_EnqueueLinkedNode(entry);return 1;
}
