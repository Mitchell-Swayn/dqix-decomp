#include <globaldefs.h>
ARM
struct GroupBits{unsigned short group:2;unsigned short rest:14;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void Zone3D_GetMainInstance();
extern "C" void* Network_GetConnectionManager();
extern "C" char* ActorPathGraph_FindGlobalOwnerByZoneId(int);
extern "C" char* _ZN9GameState27GetMaybeFieldMonsterByIndexEi(void*,int);
extern "C" void Object3D_InitializeExtendedMovementStateDefaults(void*);
extern "C" void _ZN8Object3D10MakeHiddenEv(void*);
extern "C" int Network_IsSessionActive(void*);
extern "C" int Network_IsParentOrOffline(void*);
extern "C" void Field_QueueMonsterHideRequest(int,int,int,int);
// Original: arm9/ov017 @ 0x021A33E0; symbol: HideTwelveIndexedMonstersAndPropagatePrimaryState; size: 0xb8.
extern "C" void FieldMonster_HideTrackedZoneGroupAndBroadcast(int unused,int index) {
 void* game=_ZN9GameState11GetInstanceEv();Zone3D_GetMainInstance();void* connection=Network_GetConnectionManager();char* record=ActorPathGraph_FindGlobalOwnerByZoneId(index);if(!record)return;*(int*)(record+8)=0;
 for(int i=0;i<12;i++){char* obj=_ZN9GameState27GetMaybeFieldMonsterByIndexEi(game,i+(((GroupBits*)(record+2))->group*12+112));if(obj){Object3D_InitializeExtendedMovementStateDefaults(obj);_ZN8Object3D10MakeHiddenEv(obj);if(Network_IsSessionActive(connection) && Network_IsParentOrOffline(connection))Field_QueueMonsterHideRequest(index,i,*(short*)(obj+2),-1);}}
}
