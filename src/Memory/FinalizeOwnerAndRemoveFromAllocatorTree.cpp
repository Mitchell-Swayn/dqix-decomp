#include <globaldefs.h>
#include <Memory/HMRFAllocator.h>
extern "C" void RunReverseCleanupCallbacksAndRemoveGroups(void*);
// Original: arm9/main @ 0x020BD984; symbol: func_020bd984; size: 0x18.
extern "C" void FinalizeOwnerAndRemoveFromAllocatorTree(HMRFAllocator** owner) { RunReverseCleanupCallbacksAndRemoveGroups(owner); (*owner)->RemoveFromTree(); }
