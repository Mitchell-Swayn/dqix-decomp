#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2108ea8; symbol: data_02108ea8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char PartySyncGetSharedRecordTable_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0207D78C; symbol: func_0207d78c; size: 0xC.
void *PartySync_GetSharedRecordTable(){return PartySyncGetSharedRecordTable_UnknownRoleZeroInitializedStorage;}
}
