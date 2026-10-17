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
struct Arguments { Argument entries[7]; };
struct Item { const void* vtable; char storage[0x50]; };
extern "C" const unsigned data_ov023_021fe4f0[];
extern "C" int func_ov023_021f745c(Item*,void*,unsigned,unsigned,void*,void*,unsigned,unsigned,unsigned);
// Original: arm9/ov011 @ 0x02188658; symbol: func_ov011_02188658; size: 0x11C.
extern "C" unsigned func_ov011_02188658(Arguments* self) {
 unsigned id=func_ov011_02184c30(self);
 unsigned kind=func_ov011_02184c30(self->entries+1);
 void* pointer=self->entries[2].kind==2 ? self->entries[2].pointer : 0;
 if(!pointer) return 0;
 void* second=self->entries[3].kind==2 ? self->entries[3].pointer : 0;
 if(!second) return 0;
 unsigned a=func_ov011_02184c30(self->entries+4);
 unsigned b=func_ov011_02184c30(self->entries+5);
 unsigned c=func_ov011_02184c30(self->entries+6);
 void* owner=func_ov017_021b2164();
 void* arena=FindTreeNodeForwarder(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=data_ov023_021fe4f0;
 memcpy(item,&initial,sizeof(Item));
 if(!func_ov023_021f745c(item,owner,id,kind,pointer,second,a,b,c)) return 0;
 AppendEnabledNodeToForwardChain(func_ov011_021849c8(owner),item);
 return 1;
}
