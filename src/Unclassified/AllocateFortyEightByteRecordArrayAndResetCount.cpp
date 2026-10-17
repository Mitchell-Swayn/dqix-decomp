#include <globaldefs.h>
ARM
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
// Original: arm9/main @ 0x0207F594; symbol: func_0207f594; size: 0x3C.
extern "C" void AllocateFortyEightByteRecordArrayAndResetCount(unsigned char* p,void* allocator,int count){if(!allocator)return;if(count<=0)return;*(short*)(p+4)=0;*(short*)(p+6)=count;*(void**)p=_ZN13SafeAllocator8AllocateEj(allocator,count*48);}
