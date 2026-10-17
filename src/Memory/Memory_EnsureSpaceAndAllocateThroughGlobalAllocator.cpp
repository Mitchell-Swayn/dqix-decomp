#include <globaldefs.h>
extern "C" unsigned char* GameResources_GetInstance();extern "C" unsigned Memory_ReadMaximumAlignedAllocation(void*);extern "C" unsigned AllocatorUnion_AllocateFourByteAligned(void*,unsigned);extern "C" void Filesystem_FreeCachedTableIfAllocationNeedsSpace(unsigned);extern "C" unsigned char data_02114e20[];
// Original: arm9/main @ 0x020A36CC; symbol: func_020a36cc; size: 0x54.
extern "C" ARM int Memory_EnsureSpaceAndAllocateThroughGlobalAllocator(unsigned* out,unsigned value){unsigned char* p=GameResources_GetInstance();if(Memory_ReadMaximumAlignedAllocation(data_02114e20)<value){Filesystem_FreeCachedTableIfAllocationNeedsSpace(value);p[0x4490]=1;}*out=AllocatorUnion_AllocateFourByteAligned(data_02114e20,value);return 1;}
