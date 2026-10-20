#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x21118e0; symbol: data_021118e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1568 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int *TryReadViaDMA_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020D06E8; symbol: func_020d06e8; size: 0x14.
unsigned int CardReadManager_GetBackupCommandChunkLimit(){return TryReadViaDMA_UnknownRoleZeroInitializedStorage[7];}
}
