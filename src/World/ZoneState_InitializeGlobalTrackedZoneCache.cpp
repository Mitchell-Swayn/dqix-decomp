#include <globaldefs.h>
extern "C"
{
// Original data: arm9/main @ 0x20fdd44; symbol: data_020fdd44.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 3168 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char ZoneStateGetTrackedZoneCache_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x20fdd38; symbol: data_020fdd38.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char Sinit020E5Afc_UnknownRoleZeroInitializedStorage[];
    void* ZoneState_ConstructTrackedZoneCache(void*);
    void* ZoneState_DestroyTrackedZoneCache(void*);
    void __register_global_object(void*, void (*)(void*, int), void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E5AFC; symbol: __sinit_020e5afc; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_020e5afc()
{
    ZoneState_ConstructTrackedZoneCache(ZoneStateGetTrackedZoneCache_UnknownRoleZeroInitializedStorage);
    __register_global_object(ZoneStateGetTrackedZoneCache_UnknownRoleZeroInitializedStorage, (void (*)(void*, int))ZoneState_DestroyTrackedZoneCache, Sinit020E5Afc_UnknownRoleZeroInitializedStorage);
}
