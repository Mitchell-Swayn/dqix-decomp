#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original data: arm9/main @ 0x2108efc; symbol: data_02108efc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
int _ZNK6Script9Parameter5ToIntEv(void *);extern char *ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020899BC; symbol: func_020899bc; size: 0x20.
bool Script_SetGlobalHalfwordFieldEightFromParameter(void *p){int v=_ZNK6Script9Parameter5ToIntEv(p);*(short *)(ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage+8)=v;return true;}
}
