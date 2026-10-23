#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
extern "C" GameResources* GameResources_GetInstance();
extern "C" unsigned FieldBattle_GetScene(void*);
extern "C" void BattleScene_ProcessPartyAnimationReloadQueue(void*);
extern "C" void Field_QueueNameAndCacheMemberText(int,int,const char*);
extern "C" int ProcessExistingGameObjects(void*);
extern "C" bool LinkedQueue_IsEmpty(const int*);
extern "C" void Field_CommitJoinedPartyAndWorldState(void*);
struct JoinState {unsigned char unknown[9],path,result,gap[0x26-11],stage,flags,gap2[4],kind,gap3[7];unsigned ready;};
// Original: arm9/ov017 @ 0x021B08F4; symbol: Field_WaitForPartyJoinFinalization; size: 0x188.
extern "C" ARM unsigned char Field_WaitForPartyJoinFinalization(void* object) {
JoinState* self=(JoinState*)object;
GameState::GetInstance();GameResources* resources=GameResources_GetInstance();
unsigned char* battle=(unsigned char*)resources->unknown_ptr_3718;
const int* queue=(const int*)resources->unknown_ptr_array_36fc[1];
if(battle[2]){void* scene=(void*)FieldBattle_GetScene(battle);if(scene)BattleScene_ProcessPartyAnimationReloadQueue(scene);}
if(!self->path) {
if(self->stage==0){Field_QueueNameAndCacheMemberText(5,0,0);if(ProcessExistingGameObjects(self))++self->stage;else self->stage=2;}
else if(self->stage==1){if(LinkedQueue_IsEmpty(queue))++self->stage;}
else if(self->stage==2){if(self->flags&0x10){Field_CommitJoinedPartyAndWorldState(self);Field_QueueNameAndCacheMemberText(7,0,0);++self->stage;}}
} else {
if(self->stage==0){if(self->ready){if(ProcessExistingGameObjects(self))++self->stage;else{Field_QueueNameAndCacheMemberText(6,0,0);self->stage=2;}}}
else if(self->stage==1){if(LinkedQueue_IsEmpty(queue)){Field_QueueNameAndCacheMemberText(6,0,0);++self->stage;}}
else if(self->stage==2){if(self->kind==2)Field_CommitJoinedPartyAndWorldState(self);}
}
return self->result;
}
