// Original widths and exact mangled method symbols reviewed; globals resolved by relocation targets.
#include <GameState/GameState.h>
#include <Resource/Script.h>
// Original data: arm9/main @ 0x20fdd30; symbol: data_020fdd30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108740; symbol: data_02108740.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108efc; symbol: data_02108efc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern char* ScriptWriteGlobalHalfword2A_UnknownRoleZeroInitializedStorage[];extern char* ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage[];extern int ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage[];void AllocateIndexedWordArrayAndResetCount(void*,void*,int);void* memcpy(void*,const void*,unsigned);}int SendCommandToArm7(int,int,bool);struct BitOne{unsigned char value:1;unsigned char rest:7;};
// Original: arm9/main @ 0x02068558; symbol: func_02068558; size: 0x28.
extern "C" unsigned GameState_ReadFirstPartyMemberLinkedBitFlag(GameState* g){char* p=(char*)g->GetPartyMemberByIndex(0);if(!p)return 0;char* q=*(char**)(p+0x150);return ((BitOne*)(q+0x49c))->value;}
