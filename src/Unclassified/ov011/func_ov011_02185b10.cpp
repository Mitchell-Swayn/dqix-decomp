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
struct Item { const void* vtable; char storage[0x24]; };
extern "C" const unsigned data_ov023_021fe910[];
extern "C" int InitializeTypeNineRecordArray(Item*,void*,unsigned,unsigned,unsigned);
// Original: arm9/ov011 @ 0x02185B10; symbol: func_ov011_02185b10; size: 0xD8.
extern "C" unsigned func_ov011_02185b10(void* self) {
 void* owner=func_ov017_021b2164();
 void* list=func_ov011_021849c8(owner);
 if(func_ov023_021f6880(list,0xffff)) return 0;
 unsigned kind=func_ov011_02184c30(self);
 unsigned value=func_ov011_02184c30((char*)self+8);
 void* arena=FindTreeNodeForwarder(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=data_ov023_021fe910;
 memcpy(item,&initial,sizeof(Item));
 if(!InitializeTypeNineRecordArray(item,owner,0xffff,kind,value)) return 0;
 AppendEnabledNodeToForwardChain(list,item);
 return 1;
}
