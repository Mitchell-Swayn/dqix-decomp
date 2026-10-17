#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void _ZN14AllocatorUnion4FreeEPv(void*,void*);
// Original: arm9/main @ 0x02012DA4; symbol: func_02012da4; size: 0xC.
extern "C" void Memory_FreeThroughAllocatorUnion(void* allocator,void* allocation){_ZN14AllocatorUnion4FreeEPv(allocator,allocation);}
