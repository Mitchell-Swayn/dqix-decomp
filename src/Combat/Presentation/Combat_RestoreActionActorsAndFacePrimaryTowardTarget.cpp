#include <globaldefs.h>
ARM
extern "C" int GameResources_ClearSecondaryFlags(...);
extern "C" int GameResources_GetInstance(...);
extern "C" int BattleScene_GetCamera(...);
extern "C" int GameResources_GetInstance(...);
extern "C" int Combat_GetCommandActorSnapshot(...);
extern "C" int Combat_GetIndexedActionTarget(...);
extern "C" int Object3D_SetNormalizedAngleAndUpdatePosition(...);
extern "C" int Object3D_TurnTowardIndexedObjectAndSelectTurnAnimation(...);
extern "C" int Combat_RestoreActionActorPlacementOnce(...);
extern "C" int BattleScene_GetActiveInstance(...);
extern "C" int BattleScene_ResolveCurrentActionRecord(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int _ZN9GameState19GetCombatantByIndexEi(...);
extern "C" int CombatScene_RestoreZoneOverridesWhenParityChanges(...);
extern "C" int Combat_RestoreActionActorPlacementOnce(...);
extern "C" int Combat_RestoreDeferredActorMotionAndTurns(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov025 @ 0x021EB7FC; symbol: RefreshControlAndTurnPrimaryTowardSecondary.
extern "C" void Combat_RestoreActionActorsAndFacePrimaryTowardTarget(char*self){
int state=_ZN9GameState11GetInstanceEv();int resources=GameResources_GetInstance();int control=BattleScene_GetActiveInstance();char*embedded=C(BattleScene_GetCamera(control));P(embedded,0x27c)=C(BattleScene_ResolveCurrentActionRecord(control));Combat_RestoreActionActorPlacementOnce(self);CombatScene_RestoreZoneOverridesWhenParityChanges(control,0);Combat_RestoreDeferredActorMotionAndTurns(self);if(!(W(self,0x1c4)&32)){GameResources_ClearSecondaryFlags(resources,1024);if(W(self,0x1c4)&128){int rec=BattleScene_ResolveCurrentActionRecord(control);char*first=C(Combat_GetCommandActorSnapshot(rec,0));char*second=C(Combat_GetIndexedActionTarget(rec,0));if(first&&second){char*object=C(_ZN9GameState19GetCombatantByIndexEi(state,H(first,32)));if(object){Object3D_TurnTowardIndexedObjectAndSelectTurnAnimation(object,S(second,14),0);Object3D_SetNormalizedAngleAndUpdatePosition(object,S(object,174));}}}B(embedded,0x278)=1;}W(self,0x1c4)|=32;
}
