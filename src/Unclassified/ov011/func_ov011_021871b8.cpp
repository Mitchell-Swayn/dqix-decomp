#include <globaldefs.h>
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* FindTreeNodeForwarder(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void AppendEnabledNodeToForwardChain(void*,void*);
struct Item { const void* vtable; char storage[0x2c]; };
extern "C" const unsigned data_ov023_021ff4b0[];
extern "C" int Unclassified_InitializeType19RecordFromArguments(Item*,void*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/ov011 @ 0x021871B8; symbol: func_ov011_021871b8; size: 0x110.
extern "C" unsigned func_ov011_021871b8(void* self) {
 unsigned id=func_ov011_02184c30(self);
 unsigned kind=func_ov011_02184c30((char*)self+8);
 unsigned a=func_ov011_02184c30((char*)self+16);
 unsigned b=func_ov011_02184c30((char*)self+24);
 unsigned c=func_ov011_02184c30((char*)self+32);
 unsigned d=func_ov011_02184c30((char*)self+40);
 unsigned e=func_ov011_02184c30((char*)self+48);
 unsigned f=func_ov011_02184c30((char*)self+56);
 void* owner=func_ov017_021b2164();
 void* arena=FindTreeNodeForwarder(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=data_ov023_021ff4b0;
 memcpy(item,&initial,sizeof(Item));
 if(!Unclassified_InitializeType19RecordFromArguments(item,owner,id,kind,a,b,c,d,e,f)) return 0;
 AppendEnabledNodeToForwardChain(func_ov011_021849c8(owner),item);
 return 1;
}
