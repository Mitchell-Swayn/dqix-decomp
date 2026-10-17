#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
struct State {SafeAllocator* allocators;char pad[0xb0];char* entries;char pad2[0x27];unsigned char flags;};
struct Sizes {unsigned values[5];};extern "C" Sizes data_020e8cd0;extern "C" void InitializeFixedPointScalesAndInvalidIndices(void*);
// Original: arm9/main @ 0x0208B8C4; symbol: func_0208b8c4; size: 0xDC.
extern "C" ARM void Object_AllocateFiveSafeAllocatorsAndThreeEntries(State* p,SafeAllocator* parent){p->allocators=(SafeAllocator*)parent->Allocate(100);p->entries=(char*)parent->Allocate(120);for(int i=0;i<3;i++)InitializeFixedPointScalesAndInvalidIndices(p->entries+i*40);unsigned size=0x7000;if(p->flags)size=0;Sizes sizes=data_020e8cd0;sizes.values[4]=size;for(int i=0;i<5;i++){p->allocators[i].ResetAllocatorPointer();unsigned size=sizes.values[i];void* buffer=parent->Allocate(size);p->allocators[i].CreateTypeA(buffer,size);}}
