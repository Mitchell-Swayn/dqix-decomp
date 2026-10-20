#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0202D6B8; symbol: func_0202d6b8; size: 0x10.
unsigned int Network_GetLastWirelessError(){return NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[18];}
}
