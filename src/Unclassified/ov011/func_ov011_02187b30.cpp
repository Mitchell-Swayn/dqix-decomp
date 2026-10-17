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
struct Item { const void* vtable; char storage[200]; };
extern "C" const unsigned data_ov023_021ff6b8[];
extern "C" int Object3D_InitializeParameterizedRecord(Item*,void*,unsigned,unsigned,unsigned,void*);
// Original: arm9/ov011 @ 0x02187B30; symbol: func_ov011_02187b30; size: 0xDC.
extern "C" unsigned func_ov011_02187b30(Arguments* self) {
 unsigned id=func_ov011_02184c30(self);
 unsigned kind=func_ov011_02184c30(self->entries+1);
 unsigned value=func_ov011_02184c30(self->entries+2);
 void* pointer=self->entries[3].kind==2 ? self->entries[3].pointer : 0;
 if(!pointer) return 0;
 void* owner=func_ov017_021b2164();
 void* arena=FindTreeNodeForwarder(owner,kind);
 if(!arena) return 0;

 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=data_ov023_021ff6b8;
 memcpy(item,&initial,sizeof(Item));
 if(!Object3D_InitializeParameterizedRecord(item,owner,id,kind,value,pointer)) return 0;
 AppendEnabledNodeToForwardChain(func_ov011_021849c8(owner),item);
 return 1;
}
