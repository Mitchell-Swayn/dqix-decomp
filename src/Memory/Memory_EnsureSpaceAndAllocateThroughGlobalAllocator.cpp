#include <globaldefs.h>
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char* GameResources_GetInstance();extern "C" unsigned Memory_ReadMaximumAlignedAllocation(void*);extern "C" unsigned AllocatorUnion_AllocateFourByteAligned(void*,unsigned);extern "C" void Filesystem_FreeCachedTableIfAllocationNeedsSpace(unsigned);extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/main @ 0x020A36CC; symbol: func_020a36cc; size: 0x54.
extern "C" ARM int Memory_EnsureSpaceAndAllocateThroughGlobalAllocator(unsigned* out,unsigned value){unsigned char* p=GameResources_GetInstance();if(Memory_ReadMaximumAlignedAllocation(Main_UnknownRoleZeroInitializedStorage_Variant3)<value){Filesystem_FreeCachedTableIfAllocationNeedsSpace(value);p[0x4490]=1;}*out=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,value);return 1;}
