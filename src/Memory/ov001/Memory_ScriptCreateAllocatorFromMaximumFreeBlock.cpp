#include <globaldefs.h>
ARM
struct AllocatorUnion;struct IntegerParameterView;
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" unsigned Memory_ReadMaximumAlignedAllocation(char*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" unsigned _ZNK13SafeAllocator24GetMaxPossibleAllocationEv(void*);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" char data_02114e20[];
extern "C" void* data_ov001_021658b8;
// Original: arm9/ov001 @ 0x0215E9B0; symbol: func_ov001_0215e9b0; size: 0x90.
extern "C" int Memory_ScriptCreateAllocatorFromMaximumFreeBlock(IntegerParameterView* p){
 int index=ReadScriptParameterAsInteger(p);
 if(index<0 || index>=8)return 0;
 unsigned size=Memory_ReadMaximumAlignedAllocation(data_02114e20);
 if(data_ov001_021658b8 && _ZNK13SafeAllocator24GetMaxPossibleAllocationEv(data_ov001_021658b8)<=20)return 0;
 void* allocator=_ZN13SafeAllocator8AllocateEj((unsigned)data_ov001_021658b8,20);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(allocator);
 void* memory=AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)data_02114e20,size);
 _ZN13SafeAllocator11CreateTypeAEPvj(allocator,memory,size);
 return 1;
}
