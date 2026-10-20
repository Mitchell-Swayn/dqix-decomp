#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void Memory_DestroyFourteenEmbeddedAllocators(char*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" int Memory_DestroyEmbeddedAndIndexedAllocators_SentinelTerminatedIndexList[];
// Original: arm9/ov017 @ 0x021A0470; symbol: func_ov017_021a0470; size: 0x9C.
extern "C" void Memory_DestroyEmbeddedAndIndexedAllocators(char* self) {
for(int i=0;i<4;++i)Memory_DestroyFourteenEmbeddedAllocators(self+0x12c8+i*0x5ec);
int i=0;
for(;Memory_DestroyEmbeddedAndIndexedAllocators_SentinelTerminatedIndexList[i]>=0;++i){
unsigned int index=Memory_DestroyEmbeddedAndIndexedAllocators_SentinelTerminatedIndexList[i];
void* allocation=((SafeAllocator*)(self+0x38))[index].GetSignedAllocator();
((SafeAllocator*)(self+0x38))[index].Destroy();
((SafeAllocator*)(self+0x38))[index].ResetAllocatorPointer();
if(allocation)Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);
}
}
