#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2108efc; symbol: data_02108efc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char* ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage;extern "C" int _ZNK6Script9Parameter5ToIntEv(void*);
// Original: arm9/main @ 0x02089AA0; symbol: func_02089aa0; size: 0x20.
extern "C" bool Script_SetPrimaryNameTableCount(void* parameter){int value=_ZNK6Script9Parameter5ToIntEv(parameter);*(short*)(ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage+24)=value;return true;}
