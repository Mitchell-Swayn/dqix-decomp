#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* _ZN14AllocatorUnion8AllocateEj(void*,unsigned);
// Original: arm9/main @ 0x02012DB0; symbol: func_02012db0; size: 0xC.
extern "C" void* AllocatorUnion_AllocateBytes(void* allocator,unsigned bytes){return _ZN14AllocatorUnion8AllocateEj(allocator,bytes);}
