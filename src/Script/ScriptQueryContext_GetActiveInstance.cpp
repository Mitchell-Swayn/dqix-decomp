#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2109d88; symbol: data_02109d88.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char ScriptQueryContextGetActiveInstance_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0209DCCC; symbol: func_0209dccc; size: 0x10.
extern "C" unsigned int ScriptQueryContext_GetActiveInstance() { return *(unsigned int*)(ScriptQueryContextGetActiveInstance_UnknownRoleZeroInitializedStorage+0); }
