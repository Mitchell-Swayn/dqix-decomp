#include <globaldefs.h>
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* FindTreeNodeForwarder(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void AppendEnabledNodeToForwardChain(void*,void*);
struct Item { const void* vtable; char storage[32]; };
extern "C" const unsigned data_ov023_021fef74[];
extern "C" int GameState_InitializeRecordType14(Item*,void*,unsigned,unsigned);
// Original: arm9/ov011 @ 0x021866E0; symbol: func_ov011_021866e0; size: 0xB0.
extern "C" unsigned func_ov011_021866e0(void* self) {
 unsigned id=func_ov011_02184c30(self);
 unsigned kind=func_ov011_02184c30((char*)self+8);
 void* owner=func_ov017_021b2164();
 void* arena=FindTreeNodeForwarder(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 // The temporary initializes its dispatch pointer; the setup call initializes storage.
 Item initial;
 initial.vtable=data_ov023_021fef74;
 memcpy(item,&initial,sizeof(Item));
 if(!GameState_InitializeRecordType14(item,owner,id,kind)) return 0;
 AppendEnabledNodeToForwardChain(func_ov011_021849c8(owner),item);
 return 1;
}
