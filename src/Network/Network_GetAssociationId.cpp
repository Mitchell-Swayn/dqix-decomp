// ARM instruction evidence reviewed; opaque field offsets preserve observed layout.
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0202DF58; symbol: func_0202df58; size: 0x10.
 extern "C" unsigned int Network_GetAssociationId() {return NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[0];}
