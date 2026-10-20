// Original ARM field widths and control flow reviewed; Script context uses original relocation targets.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>
// Original data: arm9/main @ 0x20f2308; symbol: data_020f2308.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 640000003c770d026500000044770d02660000004c770d026700000054770d020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x214e33c; symbol: data_0214e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {void* memcpy(void*,const void*,unsigned);void CombatStatus_ClearShieldBlockStage(void*);int GameState_ReadAttributeBits12To19(void*,int);extern char LoadFileIntoMemory_UnknownRoleZeroInitializedStorage[];extern char ScriptRecordExecuteWithBoundContext_UnknownRoleProcedureReferenceRecords[];}struct Direction{unsigned low:24;signed int value:3;unsigned high:5;};
// Original: arm9/main @ 0x0208806C; symbol: func_0208806c; size: 0x78.
extern "C" int CombatStatus_AdjustShieldBlockStageAndRefreshDuration(char* p,int add){Direction* q=(Direction*)(p+88);int v=q->value+add;if(v>2)v=2;if(v< -2)v=-2;if(!v){CombatStatus_ClearShieldBlockStage(p);return 0;}q->value=v;p[118]=5;p[153]=0;*(unsigned*)(p+24)|=1;return q->value;}
