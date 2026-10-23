#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/HMRFAllocator.h>
ARM
typedef unsigned uint;typedef unsigned char undefined1;
struct RecoveryContext {unsigned char unknown[0x94];unsigned char hpCooldown[4],mpCooldown[4],enabled;unsigned char unknown9d[11];unsigned char triggerCountdown;};
struct State {int words[12];int count;};struct Object;
extern "C" {
void* GameState_GetSerializedProgressState();
void* GameState_GetIndexList(GameState*);
void* Network_GetConnectionManager();
bool Network_IsSessionActive(int*);
unsigned GameResources_GetMaskedSecondaryFlags(int,unsigned);
void* __clear(void*,unsigned);
void GameState_CopyIndexedObjectList(GameState*,int,int*,int*);
bool LinkedQueue_IsEmpty(const int*);
void* Zone3D_GetMainInstance();
bool Script_ExecuteFirstSatisfiedTriggerGroup(void*,int,State*);
void Script_DispatchResultCommandsToWorld(State*);
void* NetworkOwnership_GetRegistry();
unsigned char NetworkOwnership_ClassifyLocalRequest(Object*,unsigned);
unsigned char GameObject_GetLadderTraversalActive(int);
int CharacterState_CountActiveMappedModifierBit14(char*);
int CharacterState_CountActiveMappedModifierBit15(char*);
void NetworkOwnership_QueueRequest(unsigned char*,unsigned char);
void PartyStatus_SetMemberChangeAnimationEnabled(char*,int,int);
int GameObject_RecoverHPByAmount(unsigned char*,int);
int GameObject_RecoverMPByAmount(unsigned short**,int);
void Network_QueueCurrentPartyMemberState(int,int,int,int);
void NetworkOwnership_ReleaseForLocalPeer(int,int);
void NetworkOwnership_ClearLocalEntry(void*,int);
}
// Original: arm9/main @ 0x0208B0F8; symbol: PartyProgress_UpdateTimedMemberRecovery; size: 0x39C.
extern "C" void PartyProgress_UpdateTimedMemberRecovery(void* context){
RecoveryContext* self=(RecoveryContext*)context;
GameState* game=GameState::GetInstance();GameResources* resources=GameResources_GetInstance();unsigned char* leader=(unsigned char*)game->GetUnknownGameObject();void* progress=GameState_GetSerializedProgressState();GameState_GetIndexList(game);int* network=(int*)Network_GetConnectionManager();char* display=*(char**)((char*)resources+0x36d0);int blocked;int release;int* queue=*(int**)((char*)resources+0x36fc);if(!leader)return;
blocked=GameResources_GetMaskedSecondaryFlags((int)resources,0x10);int members[4];State output;int count;__clear(members,16);GameState_CopyIndexedObjectList(game,*(short*)(leader+4),members,&count);
if(LinkedQueue_IsEmpty(queue)&&*(short*)(leader+0xb2)&&self->triggerCountdown){if(--self->triggerCountdown==0){output.words[3]=*(unsigned short*)Zone3D_GetMainInstance();if(Script_ExecuteFirstSatisfiedTriggerGroup(progress,25,&output))Script_DispatchResultCommandsToWorld(&output);}}
Object* registry=(Object*)NetworkOwnership_GetRegistry();release=0;
for(int i=0;i<count;++i){unsigned permission=NetworkOwnership_ClassifyLocalRequest(registry,1);unsigned char* member=(unsigned char*)game->GetPartyMemberByIndex(members[i]);
if(!Network_IsSessionActive(network)||(Network_IsSessionActive(network)&&permission!=1)){
if(!member||!*(short*)(leader+0xb2)||GameObject_GetLadderTraversalActive((int)leader)||(**(unsigned**)(member+0x130)&1)||!LinkedQueue_IsEmpty(queue)){release=1;continue;}
}
int hp=CharacterState_CountActiveMappedModifierBit14(*(char**)(member+0x150));
if(hp>0&&self->enabled&&!blocked){if(!self->hpCooldown[i]){if(permission!=2&&permission!=1)NetworkOwnership_QueueRequest((unsigned char*)registry,1);if(permission==1){PartyStatus_SetMemberChangeAnimationEnabled(display,(unsigned char)members[i],0);if(!(**(unsigned**)(member+0x130)&1))GameObject_RecoverHPByAmount(member,hp);self->hpCooldown[i]=40;if(Network_IsSessionActive(network))Network_QueueCurrentPartyMemberState(members[i],1,0,0);release=1;}}else --self->hpCooldown[i];}
int mp=CharacterState_CountActiveMappedModifierBit15(*(char**)(member+0x150));
if(mp>0&&self->enabled&&!blocked){if(!self->mpCooldown[i]){if(permission!=2&&permission!=1)NetworkOwnership_QueueRequest((unsigned char*)registry,1);if(permission==1){PartyStatus_SetMemberChangeAnimationEnabled(display,(unsigned char)members[i],0);if(!(**(unsigned**)(member+0x130)&1))GameObject_RecoverMPByAmount((unsigned short**)member,mp);self->mpCooldown[i]=40;if(Network_IsSessionActive(network))Network_QueueCurrentPartyMemberState(members[i],1,1,0);release=1;}}else --self->mpCooldown[i];}
}
if(release){unsigned state=NetworkOwnership_ClassifyLocalRequest(registry,1);if(state==1)NetworkOwnership_ReleaseForLocalPeer((int)registry,1);else if(state-3<=2)NetworkOwnership_ClearLocalEntry(registry,1);}
}
