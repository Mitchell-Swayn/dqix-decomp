#include <globaldefs.h>
// Original data: arm9/ov001 @ 0x2165800; symbol: data_ov001_02165800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov001 @ 0x021536E0; symbol: func_ov001_021536e0; size: 0x1C.
extern "C" ARM int Script_CountTextTableEntry() { ++ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage; return 1; }
