#include <globaldefs.h>
ARM
extern "C" char* GameResources_GetInstance(...);
extern "C" int CombatScene_GetStatusResourcePool(...);
extern "C" char* TextContext_GetSharedInstance(...);
extern "C" int BattleCamera_FrameObjectGroup(...);
extern "C" int Combat_UpdateSelectedObjectVisibility(...);
extern "C" int Graphics_ClearAndStageSharedBuffers(...);
extern "C" char* BattleScene_ResolveCurrentActionRecord(...);
extern "C" int BattleScene_DispatchTargetResultsByCommandCounts(...);
extern "C" int BattleScene_AdvanceActionCommand(...);
extern "C" int Combat_UpdateSelectedObjectVisibility(...);
extern "C" int BattleScene_DispatchTargetResultsByCommandCounts(...);
extern "C" int BattleScene_AdvanceActionCommand(...);
struct TransitionGlobal {char padding[8];unsigned phase,other,counter;};
// Original data: arm9/ov025 @ 0x21ef974; symbol: data_ov025_021ef974.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" TransitionGlobal BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage;
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov025 @ 0x021DC880; symbol: GameState_RunVisibilityAndTimedRecordTransition; size: 0xc0.
// GameState RunVisibilityAndTimedRecordTransition from listed field operations and calls.
extern "C" void GameState_RunVisibilityAndTimedRecordTransition(char* self){GameResources_GetInstance();CombatScene_GetStatusResourcePool(self);char* display=TextContext_GetSharedInstance();if(BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage.phase==0){BattleCamera_FrameObjectGroup(self+0xc18,0,0,0);Combat_UpdateSelectedObjectVisibility(self,4,1);Graphics_ClearAndStageSharedBuffers(display);BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage.phase=1;}if(BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage.phase==1){++BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage.counter;if(BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage.counter==15)BattleScene_DispatchTargetResultsByCommandCounts(self,BattleScene_ResolveCurrentActionRecord(self));if(BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage.counter==60)BattleScene_AdvanceActionCommand(self);}}
