#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2108f0c; symbol: data_02108f0c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 180 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char PartyProgressGetInstance_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0208A9B4; symbol: func_0208a9b4; size: 0xC.
void *PartyProgress_GetInstance(){return PartyProgressGetInstance_UnknownRoleZeroInitializedStorage;}
}
