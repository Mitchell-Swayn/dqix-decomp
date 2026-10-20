#include <globaldefs.h>
// Original data: arm9/main @ 0x20fefec; symbol: data_020fefec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { extern char NetworkGetConnectionManager_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0202AE18; symbol: func_0202ae18; size: 0xC.
void *Network_GetConnectionManager(){return NetworkGetConnectionManager_UnknownRoleZeroInitializedStorage;} }
