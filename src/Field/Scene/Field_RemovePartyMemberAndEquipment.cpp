#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma opt_propagation off
extern "C" {
void* Network_GetConnectionManager();int Network_IsSessionActive(void*);int Network_GetLocalMemberId(void*);
int Field_IsClientPartyTransitionRestricted(void*);
char* GameObject_GetLinkedIndexedState(GameObject*);void InitializeCharacterStateArraysAndDefaults(void*);
void GameState_UpdatePartyMemberPositionAndValue(void*,unsigned char);
char* Util_FindMatchingRecordOrInitializeFreeSlot(void*,int);
void LinkedQueue_RemoveNodeAndResetStatus(void*,void*);void BackgroundLoader_ClearStateAndRemoveTasks(void*);
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
unsigned short* GameState_GetPendingPartyPositionRecord(GameState*,int);
int GameObject_HasQueuedActions(GameObject*);void BackgroundLoader_RemoveObjectTaskAndResetLoadFields(GameObject*);
char* strcpy(char*,const char*);void CharacterResourceContext_InvalidateOwnerIndex(void*);
int GameState_GetPendingFieldReloadMode(GameState*);
void GameState_ClearObjectByIndex(GameState*,int);
void __clear(void*,unsigned);
GameObject* GameState_FindIndexedObjectWithFlag1000(GameState*,int);
void Field_RebuildActiveRosterAndCameraTarget(void*,int,int,int,int);
void Field_BuildMemberFollowChainAndConfigureMovement(int,void*,void*,int,int,int);
void Field_RebuildDisplayedAndProtagonistRosters(void*);
// Original data: arm9/ov017 @ 0x021D622C; object index list ending in -1.
extern const int FieldRemovePartyMemberAndEquipment_UnknownRoleInitializedBytes[13];
}
#pragma always_inline on

#pragma always_inline on
static inline int IsValidPartyMemberIndex(int index) { if(index>=0 && index<=3)return 1;return 0;}

#pragma force_active on
// Original: arm9/ov017 @ 0x02190264; symbol: func_ov017_02190264; size: 0x354.
// Removes a member and its equipment objects, compacts party order and rebuilds follow chains.
extern "C" void Field_RemovePartyMemberAndEquipment(char* self,int member) {
    if(!IsValidPartyMemberIndex(member))return;
    GameState* game=GameState::GetInstance();void* network=Network_GetConnectionManager();void* command=*(void**)(self+0x3734);
    if(Field_IsClientPartyTransitionRestricted(network)) {
        GameObject* object=game->GetPartyMemberByIndex(member);
        if(object && (*(unsigned short*)object&0x1000)) {
            char* state=GameObject_GetLinkedIndexedState(object);
            if(state){short id=*(short*)(state+0x568);InitializeCharacterStateArraysAndDefaults(state);*(short*)(state+0x568)=id;}
            GameState_UpdatePartyMemberPositionAndValue(command,(unsigned char)member);return;
        }
    }
    unsigned char* record=(unsigned char*)Util_FindMatchingRecordOrInitializeFreeSlot(self,member);
    if(record[2]){LinkedQueue_RemoveNodeAndResetStatus(*(void**)(self+0x3700),record);BackgroundLoader_ClearStateAndRemoveTasks(record);}
    GameObject* object=GameState_GetObjectWithFlag100(game,member);
    if(object) {
        if(Network_IsSessionActive(network) && (*(unsigned short*)object&0x200)){
            unsigned short* position=GameState_GetPendingPartyPositionRecord(game,member);if(position)*position=0;
        }
        if(GameObject_HasQueuedActions(object))BackgroundLoader_RemoveObjectTaskAndResetLoadFields(object);
        strcpy(self+0x435c+0x30*member,*(const char**)((char*)object+0x134));
        if(*(void**)((char*)object+0x154))CharacterResourceContext_InvalidateOwnerIndex(*(void**)((char*)object+0x154));
        if(!GameState_GetPendingFieldReloadMode(game)) {char* state=GameObject_GetLinkedIndexedState(object);if(state)InitializeCharacterStateArraysAndDefaults(state);}
    }
    struct Indices {int v[13];} indices=*(const Indices*)FieldRemovePartyMemberAndEquipment_UnknownRoleInitializedBytes;
    indices.v[0]=member;indices.v[1]=12*member+0x13;indices.v[2]=12*member+0x14;indices.v[3]=12*member+0x15;
    indices.v[4]=12*member+0x16;indices.v[5]=12*member+0x17;indices.v[6]=12*member+0x18;indices.v[7]=12*member+0x19;
    indices.v[8]=12*member+0x1a;indices.v[9]=12*member+0x1b;indices.v[10]=12*member+0x1c;indices.v[11]=12*member+0x1d;
    for(int i=0;indices.v[i]>=0;++i)GameState_ClearObjectByIndex(game,indices.v[i]);
    GameObject* ordered[4];int last[4];int previous;
    int rosterIndex;GameState* state=GameState::GetInstance();__clear(ordered,16);
    for(rosterIndex=1;rosterIndex<4;++rosterIndex){GameObject* entry=GameState_FindIndexedObjectWithFlag1000(state,rosterIndex);if(entry)ordered[*((unsigned char*)entry+0x2d2)]=entry;}
    int i;GameObject** cursor=ordered;int next=1;for(i=0;i<4;++i){GameObject* entry=*cursor;if(entry)*((unsigned char*)entry+0x2d2)=next++;cursor++;}
    if(!Network_IsSessionActive(network))Field_RebuildActiveRosterAndCameraTarget(self,1,1,1,1);
    else {
        for(int i=0;i<4;++i) {
            if(i==Network_GetLocalMemberId(network))Field_RebuildActiveRosterAndCameraTarget(self,1,1,1,1);
            else {previous=0;Field_BuildMemberFollowChainAndConfigureMovement(i,&last,&previous,1,1,1);}
        }
        Field_RebuildDisplayedAndProtagonistRosters(self);
    }
}
#pragma force_active off
