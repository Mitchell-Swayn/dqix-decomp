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
struct Arguments { Argument entries[4]; };
struct Item { char storage[0xac]; };
extern "C" Item* func_ov011_02185110(Item*);
extern "C" void func_ov011_0218513c(Item*);
extern "C" int Grotto_InitializeContainerRecord(Item*,void*,unsigned,unsigned,unsigned,void*);
// Original: arm9/ov011 @ 0x02185020; symbol: func_ov011_02185020; size: 0xF0.
extern "C" unsigned func_ov011_02185020(Arguments* self) {
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
 Item initial; func_ov011_02185110(&initial);
 memcpy(item,&initial,sizeof(Item));
 if(!Grotto_InitializeContainerRecord(item,owner,id,kind,value,pointer)) {
  func_ov011_0218513c(&initial); return 0;
 }
 AppendEnabledNodeToForwardChain(func_ov011_021849c8(owner),item);
 func_ov011_0218513c(&initial);
 return 1;
}
