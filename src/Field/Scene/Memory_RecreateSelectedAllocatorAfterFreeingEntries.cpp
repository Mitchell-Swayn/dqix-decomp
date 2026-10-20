#include <globaldefs.h>
ARM
struct AllocatorUnion;
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void WorldMap_ResetDisplayAndMarkerState(char*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov017 @ 0x21d669c; symbol: data_ov017_021d669c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 050000000c0000000f00000010000000ffffffff.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" int MemoryRecreateSelectedAllocatorAfterFreeingEntries_UnknownRoleInitializedBytes[];
// Original: arm9/ov017 @ 0x021A050C; symbol: func_ov017_021a050c; size: 0x9C.
extern "C" void Memory_RecreateSelectedAllocatorAfterFreeingEntries(unsigned char* p){
 WorldMap_ResetDisplayAndMarkerState(*(char**)(p+0x36d0));

 for(int i=0;MemoryRecreateSelectedAllocatorAfterFreeingEntries_UnknownRoleInitializedBytes[i]>=0;i++){
 int offset=MemoryRecreateSelectedAllocatorAfterFreeingEntries_UnknownRoleInitializedBytes[i]*20;
 void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0x38+offset);
 _ZN13SafeAllocator7DestroyEv(p+0x38+offset);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x38+offset);
 if(allocation)Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);
 }
 void* memory=AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)Main_UnknownRoleZeroInitializedStorage_Variant3,0x6f78);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x9c,memory,0x6f78);
}
