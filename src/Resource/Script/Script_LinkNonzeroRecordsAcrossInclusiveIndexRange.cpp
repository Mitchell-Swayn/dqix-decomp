#include <Resource/Script.h>
// Original data: arm9/main @ 0x20fdd30; symbol: data_020fdd30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void *ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage; extern "C" int ActorPathGraph_FindNodeById(void*,int); extern "C" void ActorPathGraph_AppendEdge(void*,int*);
#pragma always_inline on
static inline int Reconstruct_func_02027eec(const Script::Parameter *params) { int start=params[0].ToInt(); int end=params[1].ToInt(); struct Pair {int previous;int next;}; Pair values; values.previous=0;values.next=0; int i=start+1; values.previous=ActorPathGraph_FindNodeById(ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage,start); while(i<=end) { values.next=ActorPathGraph_FindNodeById(ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage,i); ++i; if(values.previous && values.next)ActorPathGraph_AppendEdge(ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage,(int*)&values); if(values.next)values.previous=values.next; } return 1; }
// Original: arm9/main @ 0x02027EEC; symbol: func_02027eec; size: 0xA4.
extern "C" int Script_LinkNonzeroRecordsAcrossInclusiveIndexRange(const Script::Parameter *params) { return Reconstruct_func_02027eec(params); }
