#include <globaldefs.h>
ARM
extern "C" int Input_IsKeyMaskNewlyPressed(...);
extern "C" int GameState_SetEligiblePartySlotValue100(...);
extern "C" int GameState_MarkUnflaggedListedPartyRecords(...);
extern "C" int BattleMenu_RefreshExistingPanel(...);
extern "C" int BattleMenu_ConfigureActorCommandSelection(...);
extern "C" void* memset(void*,int,unsigned);extern "C" unsigned strlen(const char*);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original data: arm9/ov000 @ 0x2184294; symbol: data_ov000_02184294.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" char BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[];
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
// Original: arm9/ov000 @ 0x0217C094; symbol: PopPartyMenuSelectionAndDispatchPreviousEntry; size: 0xc4.
extern "C" int BattleMenu_CancelPartyCommandReview(char* self){
GameState_SetEligiblePartySlotValue100(P(BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage,8));if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x802)||B(Main_UnknownRoleZeroInitializedStorage_Variant4,0x55)){GameState_MarkUnflaggedListedPartyRecords(P(BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage,8));char* stack=self+8;B(stack+*(signed char*)(stack+16),8)=0;B(stack,16)=*(signed char*)(stack+16)-1;BattleMenu_ConfigureActorCommandSelection(self,W(BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage,4),W(BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage,0));BattleMenu_RefreshExistingPanel(P(BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage,8),self,*(signed char*)(self+*(signed char*)(self+24)+16),W(BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage,4),W(BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage,0),0);}return -1;
}
