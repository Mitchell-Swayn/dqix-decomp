#include <globaldefs.h>
ARM
#include "Memory/SafeAllocator.h"
// Original: arm9/main @ 0x0204AF38; symbol: func_0204af38; size: 0x2C.
extern "C" void Graphics_AllocateScreenDescriptors(unsigned char* p,unsigned int count,SafeAllocator* allocator) { if (!allocator) return; *(void**)(p+0x10)=allocator->Allocate(count*16);p[0x1e]=count; }
