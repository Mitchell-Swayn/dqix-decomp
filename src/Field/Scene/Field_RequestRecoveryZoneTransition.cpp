#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" {
int GameState_TestTransitionRequestFlags(GameState*,unsigned);
void GameState_AddTransitionRequestFlags(GameState*,unsigned);
int GameState_ReadProtagonistObjectIndex(GameState*);
GameObject* GameState_FindIndexedObjectWithFlag1000(GameState*,int);
int GameObject_GetAssociatedPartyMemberIndex(GameObject*);
void GameObject_ReviveAndRestoreHP(GameObject*,int,int);
void GameObject_RecoverHPToMaximum(GameObject*);
void GameObject_RecoverMPToMaximum(GameObject*);
void GameObject_SetMotionStateAndRefreshAnimation(GameObject*,int);
void GameObject_SetFollowPredecessorMember(GameObject*,int);
void GameObject_SetPartyFormationOrder(GameObject*,int);
void GameObject_RequestMovementInputEnable(GameObject*);
void Field_QueueObjectFlagChange(int,int,int);
void Network_QueueCurrentPartyMemberState(int,int,int,int);
void FieldTransition_InitializeRequestDefaults(char*);
void GameState_StoreRequestedFieldTransition(GameState*,const void*);
void Field_InitializeZoneTransitionCommand(void*,int);
void LinkedQueue_AppendAndMarkActive(void*,void*);
}
#pragma force_active on
// Original: arm9/ov017 @ 0x0219FF58; symbol: func_ov017_0219ff58; size: 0x25C.
// Restores the selected party and its associated objects, then requests recovery zone 0x10D0.
extern "C" int Field_RequestRecoveryZoneTransition(char* self,int first,int second,int recoverParty) {
    GameState* game=GameState::GetInstance();
    if(GameState_TestTransitionRequestFlags(game,1)) {
    if(recoverParty) {
        GameResources_GetInstance();
        signed char member=GameState_ReadProtagonistObjectIndex(game);
        GameObject* object=game->GetPartyMemberByIndex(member);
        if(object) {
            GameObject_ReviveAndRestoreHP(object,0,1);
            GameObject_RecoverHPToMaximum(object);
            GameObject_RecoverMPToMaximum(object);
            *(unsigned*)((char*)object+0x18c)&=~1;
            GameObject_SetMotionStateAndRefreshAnimation(object,0);
            if(**(unsigned**)((char*)object+0x130)&1) {
                GameObject_SetFollowPredecessorMember(object,-1);
                GameObject_SetPartyFormationOrder(object,0);
                GameObject_RequestMovementInputEnable(object);
            }
            Field_QueueObjectFlagChange(member,1,0);
            Network_QueueCurrentPartyMemberState(member,0,0,1);
        }
        for(signed char i=0;i<4;++i) {
            object=GameState_FindIndexedObjectWithFlag1000(game,i);
            if(object && member==GameObject_GetAssociatedPartyMemberIndex(object)) {
                GameObject_ReviveAndRestoreHP(object,0,1);
                GameObject_RecoverHPToMaximum(object);
                GameObject_RecoverMPToMaximum(object);
                *(unsigned*)((char*)object+0x18c)&=~1;
                GameObject_SetMotionStateAndRefreshAnimation(object,0);
                Field_QueueObjectFlagChange(i,1,0);
                Network_QueueCurrentPartyMemberState(i,0,0,1);
            }
        }
    }
    if(first) GameState_AddTransitionRequestFlags(game,2);
    if(second) GameState_AddTransitionRequestFlags(game,4);
    if(recoverParty) GameState_AddTransitionRequestFlags(game,8);
    char request[112];
    FieldTransition_InitializeRequestDefaults(request);
    *(unsigned short*)request=0x10d0;
    request[2]=!recoverParty;request[7]=1;
    *(int*)(request+16)=-245;*(int*)(request+20)=4505;*(int*)(request+24)=-12451;
    *(unsigned short*)(request+28)=0x323d;
    GameState_StoreRequestedFieldTransition(game,request);
    if(second) {
        Field_InitializeZoneTransitionCommand(*(void**)(self+0x370c),0);
        LinkedQueue_AppendAndMarkActive(*(void**)(self+0x36fc),*(void**)(self+0x370c));
    }
    return 1;
    }
    return 0;
}
#pragma force_active off
