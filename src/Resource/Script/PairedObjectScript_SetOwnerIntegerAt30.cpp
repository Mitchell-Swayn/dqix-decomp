#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2108740; symbol: data_02108740.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char* ScriptWriteGlobalHalfword2A_UnknownRoleZeroInitializedStorage[];extern "C" int _ZNK6Script9Parameter5ToIntEv(void*);
// Original: arm9/main @ 0x0205E05C; symbol: func_0205e05c; size: 0x20.
extern "C" bool PairedObjectScript_SetOwnerIntegerAt30(void* parameter){int value=_ZNK6Script9Parameter5ToIntEv(parameter);*(int*)(ScriptWriteGlobalHalfword2A_UnknownRoleZeroInitializedStorage[1]+48)=value;return true;}
