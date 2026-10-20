#include <globaldefs.h>
#include <World/Zone3DContainers.h>
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;extern "C" void Memory_FreeThroughAllocatorUnion(AllocatorUnion*,void*);extern "C" void ResetEightZoneRenderParts(void*);struct Owner { ZoneContainerRenderPart parts[8]; char pad[4]; SafeAllocator* allocator; };
// Original: arm9/main @ 0x0202F1DC; symbol: func_0202f1dc; size: 0x70.
extern "C" void ZoneContainer_ResetRenderPartsAndDestroyAllocator(Owner* self) { ZoneContainerRenderPart* part=self->parts;for(int i=0;i<8;++i) {part->ResetIfFlag0();++part;}if(self->allocator){SignedAllocatorHeader* block=self->allocator->GetSignedAllocator();self->allocator->Destroy();Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,block);Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,self->allocator);}ResetEightZoneRenderParts(self); }
