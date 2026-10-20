#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* Network_GetConnectionManager();extern "C" char* Zone3D_GetMainInstance();extern "C" void* Network_GetCommandRecordPool();extern "C" int Network_IsSessionActive(void*);extern "C" int Network_GetLocalMemberId(void*);extern "C" void* GameResources_GetInstance();extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);struct GroupRecord{short pad;unsigned short group:2;unsigned short rest:14;};extern "C" char* ZoneState_FindCurrentTrackedZone(void*);extern "C" char* _ZN9GameState27GetMaybeFieldMonsterByIndexEi(void*,int);extern "C" void* Ov017_FindGameObjectByHalfwordId(void*,int);extern "C" void Object3D_ShallowCloneModelAndCopyAnimationIndex(void*,void*);extern "C" void GameObject_SetMotionStateAndRefreshAnimation(void*,unsigned char);
// Original: arm9/ov017 @ 0x021A2B1C; symbol: CloneFieldMonsterModelsAndMapAnimationStates; size: 0xF8.
extern "C" void FieldMonster_RefreshCurrentZoneModelClonesAndMotion(void* self){void* game=_ZN9GameState11GetInstanceEv();char* record=ZoneState_FindCurrentTrackedZone(game);if(!record)return;for(int i=0;i<12;i++){char* monster=_ZN9GameState27GetMaybeFieldMonsterByIndexEi(game,i+(112+((GroupRecord*)record)->group*12));if(!monster)continue;void* object=Ov017_FindGameObjectByHalfwordId(self,H(monster,2));if(!object)continue;Object3D_ShallowCloneModelAndCopyAnimationIndex(object,monster);switch(W(monster,0x130)){case 0:GameObject_SetMotionStateAndRefreshAnimation(monster,5);break;case 2:case 4:case 5:case 6:GameObject_SetMotionStateAndRefreshAnimation(monster,1);break;case 9:GameObject_SetMotionStateAndRefreshAnimation(monster,2);break;default:GameObject_SetMotionStateAndRefreshAnimation(monster,0);break;}}}
