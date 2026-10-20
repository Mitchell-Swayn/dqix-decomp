// ARM instruction evidence reviewed; opaque field offsets preserve observed layout.
// Original data: arm9/main @ 0x2109928; symbol: data_02109928.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char ScriptReadTenPairsIntoGlobalTable_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x02099CAC; symbol: func_02099cac; size: 0xC.
 extern "C" void* CharacterPalette_GetGlobalConfiguration() {return ScriptReadTenPairsIntoGlobalTable_UnknownRoleZeroInitializedStorage;}
