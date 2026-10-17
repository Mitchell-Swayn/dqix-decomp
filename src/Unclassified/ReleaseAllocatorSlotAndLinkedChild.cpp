#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void DetachOwnerLinksAndReturnChildToAllocatorList(void*);
// Original: arm9/main @ 0x020BC4EC; symbol: func_020bc4ec; size: 0xC.
extern "C" void ReleaseAllocatorSlotAndLinkedChild(void* p){DetachOwnerLinksAndReturnChildToAllocatorList(p);}
