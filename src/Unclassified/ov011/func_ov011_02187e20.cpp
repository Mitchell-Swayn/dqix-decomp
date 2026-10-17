#include <globaldefs.h>
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* FindTreeNodeForwarder(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void AppendEnabledNodeToForwardChain(void*,void*);
struct Item { const void* vtable; char header[0x1c]; char allocator[0x14]; char prefix34[4]; char member38[0x5c]; char member94[0x84]; };
extern "C" const unsigned data_ov004_021705f8[];
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void Object_ResetEmbeddedStateAndReturnSelf(void*);
extern "C" void InitializeRecordBuffersAndEnabledByte(void*);
extern "C" void Graphics_FinalizeRecordBuffers(void*);
extern "C" int Graphics_InitializeType15RecordResources(Item*,void*,unsigned,unsigned);
// Original: arm9/ov011 @ 0x02187E20; symbol: func_ov011_02187e20; size: 0xE4.
extern "C" unsigned func_ov011_02187e20(void* self) {
 unsigned id=func_ov011_02184c30(self);
 unsigned kind=func_ov011_02184c30((char*)self+8);
 void* owner=func_ov017_021b2164();
 void* arena=FindTreeNodeForwarder(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=data_ov004_021705f8;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(initial.allocator);
 char* members=initial.prefix34;
 Object_ResetEmbeddedStateAndReturnSelf(members+4);
 InitializeRecordBuffersAndEnabledByte(members+0x60);
 memcpy(item,&initial,sizeof(Item));
 if(!Graphics_InitializeType15RecordResources(item,owner,id,kind)) {
  Graphics_FinalizeRecordBuffers(initial.member94); return 0;
 }
 AppendEnabledNodeToForwardChain(func_ov011_021849c8(owner),item);
 Graphics_FinalizeRecordBuffers(initial.member94);
 return 1;
}
