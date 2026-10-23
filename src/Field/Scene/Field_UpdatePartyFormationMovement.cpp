#include <globaldefs.h>
#include <GameState/GameState.h>
typedef unsigned uint;typedef unsigned short ushort;
extern "C" {
void* Network_GetConnectionManager();void* GameState_ReadUnknownB0(GameState*);void* GameState_GetIndexList(GameState*);
unsigned GameResources_GetMaskedPrimaryFlags(unsigned*,unsigned);bool Input_TestKeyMask(unsigned short*,unsigned short);extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
int FieldEvent_IsQueuedOrSynchronizing(unsigned char*);void ProcessorContext_SleepOrYieldPriorityPeers(unsigned);
void Field_UpdatePartyMemberMovementAndCollision(int,int);bool Network_IsClientSession(unsigned*);
int GameObject_GetFollowPredecessorMember(int);int GameObject_GetPartyFormationOrder(int);void GameObject_UpdatePartyMovementAndActionShortcuts(void*);void Field_ResolveObjectZoneCollision(void*,void*);void Object3D_AdvanceEffectsAndClampTransitionValue(char*);void* GameResources_GetAlternateLeaderModel(void*);
}
// Original: arm9/ov017 @ 0x0218E674; symbol: Field_UpdatePartyFormationMovement; size: 0x254.
// Update queued party movers, followed followers, and the alternate leader model.
extern "C" ARM void Field_UpdatePartyFormationMovement(void* resources) {
GameState* game=GameState::GetInstance();Network_GetConnectionManager();if(!GameState_ReadUnknownB0(game))return;
unsigned char* index=(unsigned char*)GameState_GetIndexList(game);int updated[4]={};game->GetEffectiveDeltaTime();
int allow=1;if((GameResources_GetMaskedPrimaryFlags((unsigned*)resources,0x20)&&Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,1))||GameResources_GetMaskedPrimaryFlags((unsigned*)resources,0x2000))allow=0;
if(FieldEvent_IsQueuedOrSynchronizing(*(unsigned char**)((char*)resources+0x3734)))allow=0;
int yield=0;if(GameResources_GetMaskedPrimaryFlags((unsigned*)resources,0x4000))yield=1;
int count=0;for(int i=0;i<index[0xf7c];++i){if(count&&yield)ProcessorContext_SleepOrYieldPriorityPeers(1);unsigned char* entry=index+i;int member=entry[0xf78];++count;updated[member]=1;Field_UpdatePartyMemberMovementAndCollision(member,allow);}
for(int i=0;i<4;++i){if(updated[i])continue;GameObject* object=game->GetPartyMemberByIndex(i);if(!object)continue;if(count&&yield)ProcessorContext_SleepOrYieldPriorityPeers(1);++count;
if(Network_IsClientSession((unsigned*)Network_GetConnectionManager())&&object->obj3D_.GetField06()==game->GetUnknownGameObject()->obj3D_.GetField06()&&((object->obj3D_.unknown_0_&0x1000)||(object->obj3D_.unknown_4_==0&&(*(unsigned*)((char*)object+0x18c)&1)))&&GameObject_GetFollowPredecessorMember((int)object)>=0){updated[i]=1;GameObject_UpdatePartyMovementAndActionShortcuts(object);Field_ResolveObjectZoneCollision(object,0);continue;}
if(GameObject_GetPartyFormationOrder((int)object))GameObject_UpdatePartyMovementAndActionShortcuts(object);else Object3D_AdvanceEffectsAndClampTransitionValue((char*)object);}
Object3D* alternate=(Object3D*)GameResources_GetAlternateLeaderModel(resources);if(alternate)alternate->AdvanceEffects();
if(game->GetPartyMemberByIndex(0xce)){if(count&&yield)ProcessorContext_SleepOrYieldPriorityPeers(1);Field_UpdatePartyMemberMovementAndCollision(0xce,allow);}
}
