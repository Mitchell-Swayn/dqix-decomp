#include <globaldefs.h>
extern "C" void FinalizeOwnerAndRemoveFromAllocatorTree(void*);extern "C" void InitializeHandleAndSignedIndexDefaults(void*);
// Original: arm9/main @ 0x0203A950; symbol: func_0203a950; size: 0x24.
extern "C" ARM void CleanupPointedResourceAndResetOwner(void** p){if(*p)FinalizeOwnerAndRemoveFromAllocatorTree(*p);InitializeHandleAndSignedIndexDefaults(p);}
