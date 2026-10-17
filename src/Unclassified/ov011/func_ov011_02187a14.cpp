#include <globaldefs.h>
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* FindTreeNodeForwarder(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void AppendEnabledNodeToForwardChain(void*,void*);
struct Item { char storage[0xac]; };
extern "C" void* func_ov023_021f6880(void*,unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
extern "C" Item* func_ov011_02185110(Item*);
extern "C" void func_ov011_0218513c(Item*);
extern "C" int Grotto_InitializeContainerRecord(Item*,void*,unsigned,unsigned,unsigned,void*);
extern "C" void* AdvancePointerBy32Bytes(void*);
extern "C" void CopyRecordScalarFieldsAndFlagBits(void*,void*);
extern "C" void Field_SetRecordStateTwo(void*);
// Original: arm9/ov011 @ 0x02187A14; symbol: func_ov011_02187a14; size: 0x11C.
extern "C" unsigned func_ov011_02187a14(void* self) {
 unsigned id=func_ov011_02184c30(self);
 unsigned kind=func_ov011_02184c30((char*)self+8);
 unsigned from=func_ov011_02184c30((char*)self+16);
 void* owner=func_ov017_021b2164();
 void* list=func_ov011_021849c8(owner);
 void* source=func_ov023_021f6880(list,from);
 OV023_ReadHalfwordField04(source);
 void* arena=FindTreeNodeForwarder(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; func_ov011_02185110(&initial);
 memcpy(item,&initial,sizeof(Item));
 if(!Grotto_InitializeContainerRecord(item,owner,id,kind,0,0)) {
  func_ov011_0218513c(&initial); return 0;
 }
 void* fromEntries=AdvancePointerBy32Bytes(source);
 void* toEntries=AdvancePointerBy32Bytes(item);
 CopyRecordScalarFieldsAndFlagBits(fromEntries,toEntries);
 Field_SetRecordStateTwo(item);
 AppendEnabledNodeToForwardChain(list,item);
 func_ov011_0218513c(&initial);
 return 1;
}
