#include <globaldefs.h>
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* FindTreeNodeForwarder(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void AppendEnabledNodeToForwardChain(void*,void*);
struct Item { const void* vtable; char storage[0x28]; };
extern "C" const unsigned data_ov023_021ff7c4[];
extern "C" int Grotto_InitializeType13Record(Item*,void*,unsigned,unsigned,unsigned*,bool*);
// Original: arm9/ov011 @ 0x02186548; symbol: func_ov011_02186548; size: 0x108.
extern "C" unsigned func_ov011_02186548(void* self) {
 unsigned id=func_ov011_02184c30(self);
 unsigned kind=func_ov011_02184c30((char*)self+8);
 unsigned values[2]; bool flags[2];
 values[0]=func_ov011_02184c30((char*)self+16);
 values[1]=func_ov011_02184c30((char*)self+24);
 flags[0]=func_ov011_02184c30((char*)self+32)!=0;
 flags[1]=func_ov011_02184c30((char*)self+40)!=0;
 void* owner=func_ov017_021b2164();
 void* arena=FindTreeNodeForwarder(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=data_ov023_021ff7c4;
 memcpy(item,&initial,sizeof(Item));
 if(!Grotto_InitializeType13Record(item,owner,id,kind,values,flags)) return 0;
 AppendEnabledNodeToForwardChain(func_ov011_021849c8(owner),item);
 return 1;
}
