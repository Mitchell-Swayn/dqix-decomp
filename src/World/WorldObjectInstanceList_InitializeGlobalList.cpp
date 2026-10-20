#include <globaldefs.h>
extern "C"
{
// Original data: arm9/main @ 0x2109020; symbol: data_02109020.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char WorldObjectInstanceListGetInstance_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2109014; symbol: data_02109014.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char Sinit020E62B4_UnknownRoleZeroInitializedStorage[];
    void* _ZN23WorldObjectInstanceListC1Ev(void*);
    void* _ZN23WorldObjectInstanceListD1Ev(void*);
    void __register_global_object(void*, void (*)(void*, int), void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E62B4; symbol: __sinit_020e62b4; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_020e62b4()
{
    _ZN23WorldObjectInstanceListC1Ev(WorldObjectInstanceListGetInstance_UnknownRoleZeroInitializedStorage);
    __register_global_object(WorldObjectInstanceListGetInstance_UnknownRoleZeroInitializedStorage, (void (*)(void*, int))_ZN23WorldObjectInstanceListD1Ev, Sinit020E62B4_UnknownRoleZeroInitializedStorage);
}
