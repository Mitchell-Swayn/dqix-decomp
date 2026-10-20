#include <globaldefs.h>
extern "C"
{
// Original data: arm9/main @ 0x2108ea8; symbol: data_02108ea8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char PartySyncGetSharedRecordTable_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2108e9c; symbol: data_02108e9c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char Sinit020E6260_UnknownRoleZeroInitializedStorage[];
    void* PartySync_ConstructRecordTable(void*);
    void* PartySync_ReinitializeRecordTable(void*);
    void __register_global_object(void*, void (*)(void*, int), void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E6260; symbol: __sinit_020e6260; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_020e6260()
{
    PartySync_ConstructRecordTable(PartySyncGetSharedRecordTable_UnknownRoleZeroInitializedStorage);
    __register_global_object(PartySyncGetSharedRecordTable_UnknownRoleZeroInitializedStorage, (void (*)(void*, int))PartySync_ReinitializeRecordTable, Sinit020E6260_UnknownRoleZeroInitializedStorage);
}
