#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2109bb0; symbol: data_02109bb0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);extern "C" void Actor_AppendChoiceGroup(void*,int);extern "C" unsigned char* ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x0209BB1C; symbol: func_0209bb1c; size: 0x50.
extern "C" int Script_SetPresentGlobalOwnerValue(const void* parameter){if(!*(void**)(ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage+20))return 1;int value=_ZNK6Script9Parameter5ToIntEv(parameter);Actor_AppendChoiceGroup(*(void**)ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage,value);*(int*)(ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage+24)=value;return 1;}
