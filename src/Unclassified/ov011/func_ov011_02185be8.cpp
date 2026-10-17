#include <globaldefs.h>
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* FindTreeNodeForwarder(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void AppendEnabledNodeToForwardChain(void*,void*);
struct Argument { unsigned kind; void* pointer; };
struct Arguments { Argument entries[4]; };
struct Item { char header[0x24]; char member24[0x64]; };
extern "C" Item* func_ov011_02185ce0(Item*);
extern "C" void Graphics_FinalizeRecordBuffers(void*);
extern "C" int Ov023_InitializeTypeTenRecord(Item*,void*,unsigned,unsigned,unsigned,void*,unsigned);
// Original: arm9/ov011 @ 0x02185BE8; symbol: func_ov011_02185be8; size: 0xF8.
extern "C" unsigned func_ov011_02185be8(Arguments* self) {
 unsigned id=func_ov011_02184c30(self);
 unsigned kind=func_ov011_02184c30(self->entries+1);
 void* pointer=self->entries[2].kind==2 ? self->entries[2].pointer : 0;
 if(!pointer) return 0;
 unsigned value=func_ov011_02184c30(self->entries+3);
 void* owner=func_ov017_021b2164();
 void* arena=FindTreeNodeForwarder(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; func_ov011_02185ce0(&initial);
 memcpy(item,&initial,sizeof(Item));
 if(!Ov023_InitializeTypeTenRecord(item,owner,id,kind,0,pointer,value)) {
  Graphics_FinalizeRecordBuffers(initial.member24); return 0;
 }
 AppendEnabledNodeToForwardChain(func_ov011_021849c8(owner),item);
 Graphics_FinalizeRecordBuffers(initial.member24);
 return 1;
}
