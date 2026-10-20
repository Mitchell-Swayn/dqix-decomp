#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20fdd30; symbol: data_020fdd30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int _ZNK6Script9Parameter5ToIntEv(void*);extern "C" void* ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage[];extern "C" void ActorPathGraph_AllocateNodes(void*,void*,int);
// Original: arm9/main @ 0x02027F90; symbol: func_02027f90; size: 0x24.
extern "C" bool Script_InvokeGlobalPairWithIntegerCount(void* parameter){int count=_ZNK6Script9Parameter5ToIntEv(parameter);ActorPathGraph_AllocateNodes(ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage[0],ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage[1],count);return true;}
