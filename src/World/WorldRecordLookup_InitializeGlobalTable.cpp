#include <globaldefs.h>
extern "C"
{
// Original data: arm9/main @ 0x2108e10; symbol: data_02108e10.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char ActionDataGetGlobalTables_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2108e04; symbol: data_02108e04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char Sinit020E60F8_UnknownRoleZeroInitializedStorage[];
    void* WorldRecordLookup_InitializeFourTriples(void*);
    void* WorldRecordLookup_ClearFourTriplesOnDestruction(void*);
    void __register_global_object(void*, void (*)(void*, int), void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E60F8; symbol: __sinit_020e60f8; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_020e60f8()
{
    WorldRecordLookup_InitializeFourTriples(ActionDataGetGlobalTables_UnknownRoleZeroInitializedStorage);
    __register_global_object(ActionDataGetGlobalTables_UnknownRoleZeroInitializedStorage, (void (*)(void*, int))WorldRecordLookup_ClearFourTriplesOnDestruction, Sinit020E60F8_UnknownRoleZeroInitializedStorage);
}
