#include <globaldefs.h>
ARM
// Separate observed object bases are retained, as in adjacent matched FieldBattle lifecycle routines.
// Original data: arm9/main @ 0x02114E20; symbol: data_02114e20.
// Mutable zero-initialized allocator-union storage; logical extent is unresolved.
// Full storage record: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
// Original data: arm9/ov017 @ 0x021D6874; symbol: data_ov017_021d6874.
// Interleaved pool identifiers and sizes; full original values: docs/data-symbols/ov017.md.
struct TableEntry { unsigned value,next; };
extern "C" TableEntry GameResourcesRecreateSharedSubscreenAllocatorPools_UnknownRoleInitializedBytes[];
// Original data: arm9/ov017 @ 0x021D6878; symbol: data_ov017_021d6878.
// Size fields of the same interleaved pool table; zero terminates iteration.
extern "C" TableEntry GameResourcesRecreateSharedSubscreenAllocatorPools_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/ov017 @ 0x021A05A8; symbol: func_ov017_021a05a8; size: 0x88.
// Releases the current allocator and recreates the table-selected shared subscreen pools.
extern "C" void GameResources_RecreateSharedSubscreenAllocatorPools(char* resources) {
 void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(resources+0x9c);
 if(allocation) {
 _ZN13SafeAllocator7DestroyEv(resources+0x9c);
 Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);
 }
 unsigned size;
 int index=0;
 resources+=0x38;
 for(;GameResourcesRecreateSharedSubscreenAllocatorPools_UnknownRoleInitializedBytes_Variant2[index].value!=0;++index) {
 size=GameResourcesRecreateSharedSubscreenAllocatorPools_UnknownRoleInitializedBytes_Variant2[index].value;
 void* memory=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,size);
 unsigned pool=GameResourcesRecreateSharedSubscreenAllocatorPools_UnknownRoleInitializedBytes[index].value;
 _ZN13SafeAllocator11CreateTypeAEPvj(resources+pool*20,memory,size);
 }
}
