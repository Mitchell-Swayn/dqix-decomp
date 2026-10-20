#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
struct Context
{
    char pad[0x36d0];
    void* party;
};
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsParentOrOffline();
extern "C" void GameObject_SubtractHPWithOptionalDeath(void*,unsigned char,int);
extern "C" void PartyStatus_SetMemberChangeAnimationEnabled(void*,int,int);
extern "C" void PartyStatus_MarkMemberSnapshotChanged(void*,int);
extern "C" int Network_IsSessionActive(void*);
extern "C" void Network_QueueCurrentPartyMemberState(int,int,int,int);
// Original: arm9/main @ 0x0208AEBC; symbol: func_0208aebc; size: 0xBC.
extern "C" ARM void GameState_UpdatePartyMemberStatusAndNotifyChanges(char* p,int index)
{
    char* member;
    void* mode;
    void* party;
    GameState* state=GameState::GetInstance();
    char* context=(char*)GameResources_GetInstance();
    party=((Context*)context)->party;
    member=(char*)state->GetPartyMemberByIndex(index);
    mode=Network_GetConnectionManager();
    unsigned short previous=*(unsigned short*)(*(char**)(member+0x130)+4);
    if(!Network_IsParentOrOffline())*(short*)(*(char**)(member+0x130)+4)=1;
    else GameObject_SubtractHPWithOptionalDeath(member,(unsigned char)p[5],0);
    if(previous!=*(unsigned short*)(*(char**)(member+0x130)+4))
    {
        PartyStatus_SetMemberChangeAnimationEnabled(party,index,1);
        PartyStatus_MarkMemberSnapshotChanged(party,index);
    }
    if(Network_IsSessionActive(mode))Network_QueueCurrentPartyMemberState(index,1,0,1);
}
