#include <globaldefs.h>
#include <GameState/GameState.h>
#pragma force_active on
ARM
struct Owner;
struct ReceivedVocationState {
    char unknown_0[0x564];
    unsigned short sharedValue;
    char unknown_566[0x954-0x566];
};
struct VocationProgress {
    unsigned short member:3;
    unsigned short level:8;
    unsigned short vocation:4;
    unsigned short notify:1;
    unsigned short sharedValue;
    unsigned experience;
    unsigned char revocations;
    unsigned char applyImmediately;
    unsigned char learnSpells;
};
struct VocationPacket { unsigned char command; char reserved[3]; VocationProgress payload; char tail[4]; };
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" unsigned GameObject_GetLinkedIndexedState(int);
extern "C" void CharacterState_SelectAndUnlockVocation(char*,unsigned);
extern "C" void GameState_ApplyVocationLevelAndLearnSpells(unsigned,unsigned,unsigned,int,unsigned,int,int,int,int);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void GameState_QueueActorLevelChange(Owner*,int,unsigned short,unsigned,int,unsigned,unsigned,unsigned char);
// Original: arm9/ov017 @ 0x021CC830; symbol: func_ov017_021cc830; size: 0x14C.
// Applies a remote vocation-progress record, optionally processing level changes before updating experience.
extern "C" void PartySync_ApplyCurrentVocationProgress(int unused,unsigned char* record,void* gameContext,void* taskContext,void* connection)
{
    const VocationPacket* packet=(const VocationPacket*)record;
    GameState* game=(GameState*)gameContext;
    Owner* taskOwner=(Owner*)taskContext;
    GameObject* object=GameState_GetObjectWithFlag100(game,packet->payload.member);
    if(!object) return;
    ReceivedVocationState* state=(ReceivedVocationState*)GameObject_GetLinkedIndexedState((int)object);
    if(!state) return;
    unsigned vocation=packet->payload.vocation;
    CharacterState_SelectAndUnlockVocation((char*)state,vocation);
    *(unsigned short*)((unsigned char*)state+0x16c+vocation*2)=packet->payload.level;
    *((unsigned char*)state+0x186+vocation)=packet->payload.revocations;
    if(packet->payload.notify) {
        if(packet->payload.applyImmediately) {
            unsigned short oldValue=state->sharedValue;
            GameState_ApplyVocationLevelAndLearnSpells(packet->payload.member,packet->payload.level,vocation,0,packet->payload.learnSpells,0,0,0,0);
            if(GameState_ReadProtagonistObjectIndex(game)==packet->payload.member) state->sharedValue=oldValue;
        } else {
            unsigned flags=0;
            flags|=3;
            if(!packet->payload.learnSpells) flags|=4;
            GameState_QueueActorLevelChange(taskOwner,packet->payload.member,packet->payload.level,vocation,0,flags,packet->payload.experience,packet->payload.learnSpells);
            return;
        }
    }
    *(unsigned*)((unsigned char*)state+0x138+vocation*4)=packet->payload.experience;
}
