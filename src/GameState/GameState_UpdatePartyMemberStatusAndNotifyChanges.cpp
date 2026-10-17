#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
struct Context
{
    char pad[0x36d0];
    void* party;
};
extern "C" void* Object_GetGlobalConnectionState();
extern "C" int TestInactiveOrPrimaryIndexState();
extern "C" void SubtractLinkedHalfwordCountWithOptionalEmptyState(void*,unsigned char,int);
extern "C" void WriteIndexedField558Boolean(void*,int,int);
extern "C" void SetGlobalRecordStrideThirtyTwoFirstByte(void*,int);
extern "C" int IsFirstWordNonzero(void*);
extern "C" void QueueCharacterStatePacketTypeFour(int,int,int,int);
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
    mode=Object_GetGlobalConnectionState();
    unsigned short previous=*(unsigned short*)(*(char**)(member+0x130)+4);
    if(!TestInactiveOrPrimaryIndexState())*(short*)(*(char**)(member+0x130)+4)=1;
    else SubtractLinkedHalfwordCountWithOptionalEmptyState(member,(unsigned char)p[5],0);
    if(previous!=*(unsigned short*)(*(char**)(member+0x130)+4))
    {
        WriteIndexedField558Boolean(party,index,1);
        SetGlobalRecordStrideThirtyTwoFirstByte(party,index);
    }
    if(IsFirstWordNonzero(mode))QueueCharacterStatePacketTypeFour(index,1,0,1);
}
