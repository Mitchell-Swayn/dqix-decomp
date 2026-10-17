#include <globaldefs.h>
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* FindTreeNodeForwarder(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void AppendEnabledNodeToForwardChain(void*,void*);
extern "C" float func_ov011_02184c4c(void*);
struct Item { const void* vtable; char storage[76]; };
extern "C" const unsigned data_ov023_021fe708[];
extern "C" int func_ov023_021f89f4(Item*,void*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/ov011 @ 0x0218598C; symbol: func_ov011_0218598c; size: 0x134.
extern "C" unsigned func_ov011_0218598c(void* self) {
 unsigned id=func_ov011_02184c30(self);
 unsigned kind=func_ov011_02184c30((char*)self+8);
 unsigned a=func_ov011_02184c30((char*)self+16);
 unsigned b=func_ov011_02184c30((char*)self+24);
 unsigned c=func_ov011_02184c30((char*)self+32);
 int d=(int)func_ov011_02184c4c((char*)self+40);
 int e=(int)func_ov011_02184c4c((char*)self+48);
 int f=(int)func_ov011_02184c4c((char*)self+56);
 int g=(int)func_ov011_02184c4c((char*)self+64);
 void* owner=func_ov017_021b2164();
 void* arena=FindTreeNodeForwarder(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=data_ov023_021fe708;
 memcpy(item,&initial,sizeof(Item));
 if(!func_ov023_021f89f4(item,owner,id,kind,a,b,c,d,e,f,g)) return 0;
 AppendEnabledNodeToForwardChain(func_ov011_021849c8(owner),item);
 return 1;
}
