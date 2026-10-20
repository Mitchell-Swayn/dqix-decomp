#include <globaldefs.h>
ARM
#include <Memory/HMRFAllocator.h>
extern "C" int InitializeAllocatorListAndValidateState(unsigned,HMRFAllocator*);
// Original: arm9/main @ 0x020BD914; symbol: func_020bd914; size: 0x70.
extern "C" unsigned ResourceAllocator_CreateAlignedHeapRegion(unsigned start,unsigned size){unsigned end=start+size;unsigned aligned=(start+3)&~3U;if(aligned>end)return 0;unsigned remaining=end-aligned;if(remaining<16)return 0;HMRFAllocator* allocator=HMRFAllocator::CreateAtLocation((void*)(aligned+16),remaining-16,0);if(!allocator)return 0;if(InitializeAllocatorListAndValidateState(aligned,allocator))return aligned;allocator->RemoveFromTree();return 0;}
