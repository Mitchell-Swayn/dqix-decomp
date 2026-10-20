#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
struct State {SafeAllocator* allocators;char pad[0xb0];char* entries;char pad2[0x27];unsigned char flags;};
// Original data: arm9/main @ 0x20e8cd0; symbol: data_020e8cd0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00040000000a0000000800000004000000000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Sizes {unsigned values[5];};extern "C" Sizes ObjectAllocateFiveSafeAllocatorsAndThreeEntries_UnknownRoleInitializedBytes;extern "C" void Graphics_InitializeSpriteTransformDefaults(void*);
// Original: arm9/main @ 0x0208B8C4; symbol: func_0208b8c4; size: 0xDC.
extern "C" ARM void Object_AllocateFiveSafeAllocatorsAndThreeEntries(State* p,SafeAllocator* parent){p->allocators=(SafeAllocator*)parent->Allocate(100);p->entries=(char*)parent->Allocate(120);for(int i=0;i<3;i++)Graphics_InitializeSpriteTransformDefaults(p->entries+i*40);unsigned size=0x7000;if(p->flags)size=0;Sizes sizes=ObjectAllocateFiveSafeAllocatorsAndThreeEntries_UnknownRoleInitializedBytes;sizes.values[4]=size;for(int i=0;i<5;i++){p->allocators[i].ResetAllocatorPointer();unsigned size=sizes.values[i];void* buffer=parent->Allocate(size);p->allocators[i].CreateTypeA(buffer,size);}}
