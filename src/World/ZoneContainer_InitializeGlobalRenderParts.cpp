#include <globaldefs.h>
extern "C"
{
// Original data: arm9/main @ 0x2104b6c; symbol: data_02104b6c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1752 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char ZoneContainerGetGlobalRenderParts_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2104b60; symbol: data_02104b60.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char Sinit020E5C00_UnknownRoleZeroInitializedStorage[];
    void* ZoneContainer_ConstructTwoArraysOfFiveRenderParts(void*);
    void* ZoneContainer_DestroyTenRenderParts(void*);
    void __register_global_object(void*, void (*)(void*, int), void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E5C00; symbol: __sinit_020e5c00; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_020e5c00()
{
    ZoneContainer_ConstructTwoArraysOfFiveRenderParts(ZoneContainerGetGlobalRenderParts_UnknownRoleZeroInitializedStorage);
    __register_global_object(ZoneContainerGetGlobalRenderParts_UnknownRoleZeroInitializedStorage, (void (*)(void*, int))ZoneContainer_DestroyTenRenderParts, Sinit020E5C00_UnknownRoleZeroInitializedStorage);
}
