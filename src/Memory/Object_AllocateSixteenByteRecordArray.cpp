#include <globaldefs.h>
ARM
#include "Memory/SafeAllocator.h"
// Original: arm9/main @ 0x020278E4; symbol: func_020278e4; size: 0x2C.
extern "C" void Object_AllocateSixteenByteRecordArray(unsigned char* p,unsigned int count,SafeAllocator* allocator) { *(void**)(p+0x2c)=allocator->Allocate(count*16);*(unsigned int*)(p+0x30)=0;*(unsigned int*)(p+0x34)=count; }
