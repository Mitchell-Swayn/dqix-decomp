#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2112140; symbol: data_02112140.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int CardReadManagerReadGlobalStatus_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020D1198; symbol: func_020d1198; size: 0x10.
unsigned int CardReadManager_ReadGlobalStatus(){return CardReadManagerReadGlobalStatus_UnknownRoleZeroInitializedStorage;}
}
