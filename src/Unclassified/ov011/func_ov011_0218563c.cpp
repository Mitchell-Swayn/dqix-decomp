#include <globaldefs.h>
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* FindTreeNodeForwarder(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void AppendEnabledNodeToForwardChain(void*,void*);
extern "C" void* func_ov023_021f6880(void*,unsigned);
struct Argument { unsigned kind; void* pointer; };
struct Arguments { Argument entries[4]; };
struct Item { const void* vtable; char storage[44]; };
extern "C" const unsigned data_ov023_021fea34[];
extern "C" int Ov023_InitializeTypeFourRecord(Item*,void*,unsigned,unsigned,unsigned,void*,unsigned);
// Original: arm9/ov011 @ 0x0218563C; symbol: func_ov011_0218563c; size: 0xE4.
extern "C" unsigned func_ov011_0218563c(Arguments* self) {
 unsigned id=func_ov011_02184c30(self);
 unsigned kind=func_ov011_02184c30(self->entries+1);

 void* pointer=self->entries[2].kind==2 ? self->entries[2].pointer : 0;
 if(!pointer) return 0;
 void* owner=func_ov017_021b2164();
 void* arena=FindTreeNodeForwarder(owner,kind);
 if(!arena) return 0;
 unsigned value=func_ov011_02184c30(self->entries+3);
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=data_ov023_021fea34;
 memcpy(item,&initial,sizeof(Item));
 if(!Ov023_InitializeTypeFourRecord(item,owner,id,kind,0,pointer,value)) return 0;
 AppendEnabledNodeToForwardChain(func_ov011_021849c8(owner),item);
 return 1;
}
