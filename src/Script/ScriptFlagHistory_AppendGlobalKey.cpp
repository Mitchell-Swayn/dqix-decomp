#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original data: arm9/main @ 0x21098f4; symbol: data_021098f4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short ScriptFlagHistoryAppendGlobalKey_UnknownRoleZeroInitializedStorage[];extern "C" void ScriptFlagHistory_AppendKey(unsigned short*,unsigned);
// Original: arm9/main @ 0x0209953C; symbol: func_0209953c; size: 0x18.
extern "C" void ScriptFlagHistory_AppendGlobalKey(unsigned value){ScriptFlagHistory_AppendKey(ScriptFlagHistoryAppendGlobalKey_UnknownRoleZeroInitializedStorage,value);}
