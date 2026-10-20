#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2107800; symbol: data_02107800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int TextContextGetSharedInstance_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020429D4; symbol: func_020429d4; size: 0x10.
unsigned int Text_GetSharedResourceScratchBuffer(){return TextContextGetSharedInstance_UnknownRoleZeroInitializedStorage;}
}
