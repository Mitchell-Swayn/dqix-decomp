#include <globaldefs.h>
ARM
#include "Memory/SafeAllocator.h"
// Original: arm9/main @ 0x02094CDC; symbol: func_02094cdc; size: 0x24.
extern "C" void ZoneState2724_AllocateEntries(void** p,unsigned int count,SafeAllocator* allocator) { *p=allocator->Allocate(count*20); }
