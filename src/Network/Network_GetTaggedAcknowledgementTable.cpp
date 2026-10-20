#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2153660; symbol: data_02153660.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char NetworkGetTaggedAcknowledgementTable_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020E3808; symbol: func_020e3808; size: 0xC.
void *Network_GetTaggedAcknowledgementTable(){return NetworkGetTaggedAcknowledgementTable_UnknownRoleZeroInitializedStorage;}
}
