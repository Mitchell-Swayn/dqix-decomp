#include <globaldefs.h>
ARM
extern "C" unsigned* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
// Original: arm9/main @ 0x02054F3C; symbol: func_02054f3c; size: 0x44.
extern "C" bool Object_AllocateAndClearTwelveByteSecondaryRecord(unsigned** p,void* allocator){if(!allocator)return false;unsigned* q=_ZN13SafeAllocator8AllocateEj(allocator,12);*p=q;if(!q)return false;q[0]=0;q[1]=0;q[2]=0;return true;}
