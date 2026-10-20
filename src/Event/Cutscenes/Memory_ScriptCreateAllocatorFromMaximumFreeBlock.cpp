#include <globaldefs.h>
ARM
struct AllocatorUnion;struct IntegerParameterView;
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" unsigned Memory_ReadMaximumAlignedAllocation(char*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" unsigned _ZNK13SafeAllocator24GetMaxPossibleAllocationEv(void*);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" void* EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov001 @ 0x0215E9B0; symbol: func_ov001_0215e9b0; size: 0x90.
extern "C" int Memory_ScriptCreateAllocatorFromMaximumFreeBlock(IntegerParameterView* p){
 int index=Script_ReadParameterAsInteger(p);
 if(index<0 || index>=8)return 0;
 unsigned size=Memory_ReadMaximumAlignedAllocation(Main_UnknownRoleZeroInitializedStorage_Variant3);
 if(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage && _ZNK13SafeAllocator24GetMaxPossibleAllocationEv(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage)<=20)return 0;
 void* allocator=_ZN13SafeAllocator8AllocateEj((unsigned)EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage,20);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(allocator);
 void* memory=AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)Main_UnknownRoleZeroInitializedStorage_Variant3,size);
 _ZN13SafeAllocator11CreateTypeAEPvj(allocator,memory,size);
 return 1;
}
