#include <globaldefs.h>
ARM
// Original data: arm9/ov023 @ 0x21fff08; symbol: data_ov023_021fff08.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" unsigned int ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov023 @ 0x021F5598; symbol: func_ov023_021f5598; size: 0x10.
extern "C" void OnlineContent_SetMarketReferenceTable(unsigned int value) { ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage[1] = value; }
