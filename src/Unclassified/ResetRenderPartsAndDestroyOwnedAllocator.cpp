#include <globaldefs.h>
#include <World/Zone3DContainers.h>
#include <Memory/SafeAllocator.h>
extern "C" AllocatorUnion data_02114e20;extern "C" void Memory_FreeThroughAllocatorUnion(AllocatorUnion*,void*);extern "C" void ResetEightZoneRenderParts(void*);struct Owner { ZoneContainerRenderPart parts[8]; char pad[4]; SafeAllocator* allocator; };
// Original: arm9/main @ 0x0202F1DC; symbol: func_0202f1dc; size: 0x70.
extern "C" void ResetRenderPartsAndDestroyOwnedAllocator(Owner* self) { ZoneContainerRenderPart* part=self->parts;for(int i=0;i<8;++i) {part->ResetIfFlag0();++part;}if(self->allocator){SignedAllocatorHeader* block=self->allocator->GetSignedAllocator();self->allocator->Destroy();Memory_FreeThroughAllocatorUnion(&data_02114e20,block);Memory_FreeThroughAllocatorUnion(&data_02114e20,self->allocator);}ResetEightZoneRenderParts(self); }
