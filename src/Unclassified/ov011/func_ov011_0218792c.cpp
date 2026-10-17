#include <globaldefs.h>
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* FindTreeNodeForwarder(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void AppendEnabledNodeToForwardChain(void*,void*);
struct Item { const void* vtable; char storage[0x50]; };
extern "C" const unsigned data_ov023_021fe4f0[];
extern "C" int func_ov023_021f745c(Item*,void*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/ov011 @ 0x0218792C; symbol: func_ov011_0218792c; size: 0xE8.
extern "C" unsigned func_ov011_0218792c(void* self) {
 unsigned id=func_ov011_02184c30(self);
 unsigned kind=func_ov011_02184c30((char*)self+8);
 unsigned first=func_ov011_02184c30((char*)self+16);
 unsigned second=func_ov011_02184c30((char*)self+24);
 unsigned third=func_ov011_02184c30((char*)self+32);
 void* owner=func_ov017_021b2164();
 void* arena=FindTreeNodeForwarder(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=data_ov023_021fe4f0;
 memcpy(item,&initial,sizeof(Item));
 if(!func_ov023_021f745c(item,owner,id,kind,0,0,first,second,third)) return 0;
 AppendEnabledNodeToForwardChain(func_ov011_021849c8(owner),item);
 return 1;
}
