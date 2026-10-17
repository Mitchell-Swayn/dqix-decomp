#include <globaldefs.h>
#include <std_library_functions.h>
struct PackedResourceHeader { unsigned blockCount:12, tailSize:19, ownsStorage:1; };
struct SplitResource { PackedResourceHeader header; void* blocks; void* tail; };
extern "C" unsigned ExtractLowTwelveBitsAndShiftBySix(SplitResource*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
// Original: arm9/main @ 0x020a8e9c; symbol: func_020a8e9c; size: 0xc4.
// Copy the packed header, allocate the 64-byte block area and trailing bytes, then mark ownership.
extern "C" void CopySplitResourceIntoAllocatedStorage(SplitResource* resource,void* allocator,const unsigned char* serialized) {
 unsigned blocks,tail;
 if(!allocator || !serialized) return;
 memcpy(resource,serialized,4);
 blocks=ExtractLowTwelveBitsAndShiftBySix(resource);
 tail=resource->header.tailSize;
 if(blocks) resource->blocks=_ZN13SafeAllocator8AllocateEj(allocator,blocks); else resource->blocks=0;
 if(tail) resource->tail=_ZN13SafeAllocator8AllocateEj(allocator,tail); else resource->tail=0;
 if(resource->blocks) memcpy(resource->blocks,serialized+4,blocks);
 if(resource->tail) memcpy(resource->tail,serialized+(ExtractLowTwelveBitsAndShiftBySix(resource)+4),tail);
 resource->header.ownsStorage=1;
}
