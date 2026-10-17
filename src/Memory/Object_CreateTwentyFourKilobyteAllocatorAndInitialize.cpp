#include <globaldefs.h>
#pragma optimization_level 4
#include "Memory/SafeAllocator.h"
extern "C" void ResetEmbeddedAllocatorAndTwelveObjectRecords(void*);
// Original: arm9/main @ 0x020D6EC8; symbol: func_020d6ec8; size: 0x44.
extern "C" ARM void Object_CreateTwentyFourKilobyteAllocatorAndInitialize(void* p,SafeAllocator* source){SafeAllocator* alloc=(SafeAllocator*)((char*)p+0xa28);alloc->ResetAllocatorPointer();void* buffer=source->Allocate(0x6000);((SafeAllocator*)((char*)p+0xa28))->CreateTypeA(buffer,0x6000);ResetEmbeddedAllocatorAndTwelveObjectRecords(p);}
