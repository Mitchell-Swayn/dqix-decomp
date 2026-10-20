#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x21536c4; symbol: data_021536c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);extern "C" void VideoCaptions_AllocateEntries(void*,void*,int);extern "C" void* ScriptExecuteCodeWithTwoOwnersAndReturnZero_UnknownRoleZeroInitializedStorage[2];
// Original: arm9/main @ 0x020E5728; symbol: func_020e5728; size: 0x28.
extern "C" int Script_DispatchConvertedIntegerToTwoGlobalOwners(const void* p){int n=_ZNK6Script9Parameter5ToIntEv(p);VideoCaptions_AllocateEntries(ScriptExecuteCodeWithTwoOwnersAndReturnZero_UnknownRoleZeroInitializedStorage[1],ScriptExecuteCodeWithTwoOwnersAndReturnZero_UnknownRoleZeroInitializedStorage[0],n);return 1;}
