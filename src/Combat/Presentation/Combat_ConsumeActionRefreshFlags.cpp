#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadUnknownB0(void*);
extern "C" void* GameState_ReadPResources(void*);
extern "C" void BattleScene_GetActiveInstance(void*);
extern "C" void BattleCamera_ResetShotAndTransitions(void*,int,int,int);
// Original data: arm9/ov025 @ 0x21ef9a4; symbol: data_ov025_021ef9a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
// Original data: arm9/ov025 @ 0x21ef9c0; symbol: data_ov025_021ef9c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage_Variant2,CombatConsumeActionRefreshFlags_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov025 @ 0x021E9A94; symbol: ConsumeGlobalRefreshFlagsAndIncrementCounter; size: 0x98.
extern "C" void Combat_ConsumeActionRefreshFlags(char* self) {
 void* gs=_ZN9GameState11GetInstanceEv();void* data=GameState_ReadUnknownB0(gs);BattleScene_GetActiveInstance(GameState_ReadPResources(gs));
 if(CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage_Variant2&1)CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage_Variant2=(CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage_Variant2|8)&~1;
 if(!(CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage_Variant2&2))return;
 if(!*(int*)(self+0x1c0))BattleCamera_ResetShotAndTransitions(data,1,1,1);
 CombatConsumeActionRefreshFlags_UnknownRoleZeroInitializedStorage++;CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage_Variant2&=~2;
}
