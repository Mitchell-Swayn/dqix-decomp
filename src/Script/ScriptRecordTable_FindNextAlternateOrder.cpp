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
// Original: arm9/main @ 0x02072238; symbol: func_02072238; size: 0x6C.
extern "C" char* ScriptRecordTable_FindNextAlternateOrder(char* p,int threshold){unsigned count=*(unsigned short*)(p+10);char* data=*(char**)(p+4);char* result=0;int best=32767;for(unsigned short i=0;i<count;++i){char* q=data+i*32;if((*(unsigned*)(q+16)<<10)>>31){int id=*(short*)(q+26);if(id>threshold&&best>id&&*(short*)(q+22)<=0){best=id;result=q;}}}return result;}
