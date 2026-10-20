#include <globaldefs.h>
ARM
struct Reset;struct AllocatorUnion;
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* ZoneState_GetTrackedZoneCache();
extern "C" char* GetBoundedEntryAtStride318(void*,int);
extern "C" void ZoneState_ResetTrackedZone(Reset*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/ov017 @ 0x0219FEC0; symbol: func_ov017_0219fec0; size: 0x98.
extern "C" void Memory_RecreateFourEntryAllocatorPools() {
Zone3D_GetMainInstance();
void* state=ZoneState_GetTrackedZoneCache();
char* entry=GetBoundedEntryAtStride318(state,0);
ZoneState_ResetTrackedZone((Reset*)entry);
void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(*(void**)(entry+0x10));
if(allocation) {
_ZN13SafeAllocator7DestroyEv(*(void**)(entry+0x10));
Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);
}
for(int i=0;i<4;++i) {
char* e=GetBoundedEntryAtStride318(state,i);
void* p=AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)Main_UnknownRoleZeroInitializedStorage_Variant3,0x28a0);
_ZN13SafeAllocator11CreateTypeAEPvj(*(void**)(e+0x10),p,0x28a0);
}
}
