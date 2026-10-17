#include <globaldefs.h>
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* FindTreeNodeForwarder(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void AppendEnabledNodeToForwardChain(void*,void*);
struct Item { const void* vtable; char storage[72]; };
extern "C" const unsigned data_ov023_021fec60[];
extern "C" int func_ov023_021fad84(Item*,void*,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/ov011 @ 0x02185D04; symbol: func_ov011_02185d04; size: 0xD0.
extern "C" unsigned func_ov011_02185d04(void* self) {
 unsigned id=func_ov011_02184c30(self);
 unsigned kind=func_ov011_02184c30((char*)self+8);
 unsigned first=func_ov011_02184c30((char*)self+16);
 unsigned second=func_ov011_02184c30((char*)self+24);
 void* owner=func_ov017_021b2164();
 void* arena=FindTreeNodeForwarder(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial;
 initial.vtable=data_ov023_021fec60;
 memcpy(item,&initial,sizeof(Item));
 if(!func_ov023_021fad84(item,owner,id,kind,first,second)) return 0;
 AppendEnabledNodeToForwardChain(func_ov011_021849c8(owner),item);
 return 1;
}
