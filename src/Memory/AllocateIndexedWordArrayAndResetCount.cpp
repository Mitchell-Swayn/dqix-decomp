#include <globaldefs.h>
ARM
#include "Memory/SafeAllocator.h"
// Original: arm9/main @ 0x0202834C; symbol: func_0202834c; size: 0x2C.
extern "C" void AllocateIndexedWordArrayAndResetCount(unsigned char* p,SafeAllocator* allocator,unsigned int count) { *(void**)(p+0x28)=allocator->Allocate(count*4);p[0x25]=0;p[0x24]=count; }
