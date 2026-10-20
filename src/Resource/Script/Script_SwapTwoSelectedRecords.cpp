#include <globaldefs.h>
ARM
namespace Script { struct Parameter { char data[8]; int ToInt() const; }; }
// Original data: arm9/main @ 0x20fdd30; symbol: data_020fdd30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void *ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage; extern "C" void *ActorPathGraph_FindNodeById(void *,int); extern "C" void ActorPathGraph_AppendEdge(void *,void **);
// Original: arm9/main @ 0x02027DB0; symbol: func_02027db0; size: 0x94.
extern "C" int Script_SwapTwoSelectedRecords(const Script::Parameter *args) { void *pair[2]; pair[1]=0; pair[0]=0; int first=args[0].ToInt(); int second=args[1].ToInt(); if(first==second) return 0; pair[0]=ActorPathGraph_FindNodeById(ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage,first); pair[1]=ActorPathGraph_FindNodeById(ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage,second); if(!pair[0]||!pair[1]) return 0; ActorPathGraph_AppendEdge(ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage,pair); return 1; }
