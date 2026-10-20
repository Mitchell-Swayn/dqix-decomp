#include <globaldefs.h>
#include "GameState/GameState.h"
ARM
#pragma force_active on
struct Record;
struct TargetActionResult {unsigned char status,pad;short amount;unsigned char unlisted,pad5;};
extern "C" {
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
void* Network_GetConnectionManager();
bool Network_IsSessionActive(int*);
void PartyMenu_ClearTargetActionResult(Record*);
int GameState_TestMatchingOrCompatibleObjectIdentifiers(int,int,int);
bool PartyMenu_HasTargetActionBlocker(int,int);
int GameState_IncrementSelectedPackedAttribute(char*,int);
void CharacterState_RecalculateOrPreviewDerivedStats(void*,void*);
void CharacterState_QueueVocationStatBonuses(int,int,int);
void Network_QueueCurrentPartyMemberState(int,int,int,int);
}
// Original: arm9/ov002 @ 0x021546C8; symbol: func_ov002_021546c8; size: 0x15C.
extern "C" int PartyMenu_ApplyStatIncreaseItemToTargets(void* owner,void* selection,void* itemRecord,int alternate) {
    char* self=(char*)selection;
    if(!self) return 0;
    if(!itemRecord) return 0;
    GameState* game=GameState::GetInstance();
    void* network=Network_GetConnectionManager();
    int changed=0;
    TargetActionResult* results=(TargetActionResult*)(self+8);
    if(alternate) results=(TargetActionResult*)(self+0x20);
    for(int i=0;i<4;i++) PartyMenu_ClearTargetActionResult((Record*)(results+i));
    for(int i=0;i<(unsigned char)self[3];i++) {
        TargetActionResult* result=results+i;
        int target=*(signed char*)(self+4+i);
        if(!GameState_TestMatchingOrCompatibleObjectIdentifiers((int)owner,target,*(signed char*)(self+2))) {
            result->status=1;
        } else if(PartyMenu_HasTargetActionBlocker((int)owner,target)) {
            result->status=2;
        } else {
            GameObject* object=GameState_GetObjectWithFlag100(game,target);
            if(object) {
                result->amount=GameState_IncrementSelectedPackedAttribute(*(char**)((char*)object+0x150),*(short*)self);
                if(result->amount>0) {
                    result->status=3;
                    CharacterState_RecalculateOrPreviewDerivedStats(*(void**)((char*)object+0x150),0);
                    if(Network_IsSessionActive((int*)network)) {
                        CharacterState_QueueVocationStatBonuses(target,(unsigned char)*(unsigned*)(*(char**)((char*)object+0x150)+0x950),1);
                        Network_QueueCurrentPartyMemberState(target,0,0,1);
                    }
                    changed=1;
                }
            }
        }
    }
    return changed;
}
