#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2153637; symbol: data_02153637.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 41 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char NetworkOwnershipGetRegistry_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020E2FF8; symbol: func_020e2ff8; size: 0xC.
void *NetworkOwnership_GetRegistry(){return NetworkOwnershipGetRegistry_UnknownRoleZeroInitializedStorage;}
}
