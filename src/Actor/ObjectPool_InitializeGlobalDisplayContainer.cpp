#include <globaldefs.h>
extern "C"
{
// Original data: arm9/main @ 0x21079ec; symbol: data_021079ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 3412 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char ObjectGetGlobalSixteenEntryDisplayState_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x21079e0; symbol: data_021079e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char Sinit020E5Eb4_UnknownRoleZeroInitializedStorage[];
    void* ObjectPool_ConstructDisplayContainer(void*);
    void* GameState_ResetSixteenObjectSlots208Through223AndReturnPointer(void*);
    void __register_global_object(void*, void (*)(void*, int), void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E5EB4; symbol: __sinit_020e5eb4; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_020e5eb4()
{
    ObjectPool_ConstructDisplayContainer(ObjectGetGlobalSixteenEntryDisplayState_UnknownRoleZeroInitializedStorage);
    __register_global_object(ObjectGetGlobalSixteenEntryDisplayState_UnknownRoleZeroInitializedStorage, (void (*)(void*, int))GameState_ResetSixteenObjectSlots208Through223AndReturnPointer, Sinit020E5Eb4_UnknownRoleZeroInitializedStorage);
}
