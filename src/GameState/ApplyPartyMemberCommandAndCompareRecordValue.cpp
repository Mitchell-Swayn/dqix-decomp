#include <globaldefs.h>
ARM
#include "GameState/GameState.h"
extern "C" int GameObject_SubtractHPWithOptionalDeath(void*,int,int); extern "C" void PartyStatus_SetMemberChangeAnimationEnabled(void*,int,int); extern "C" void PartyStatus_MarkMemberSnapshotChanged(void*,int); extern "C" void* Network_GetConnectionManager(); extern "C" bool Network_IsSessionActive(void*); extern "C" void Network_QueueCurrentPartyMemberState(int,int,int,int);
struct Record { unsigned char pad[4]; unsigned short value; }; struct Object { unsigned char pad[0x130]; Record* record; };
// Original: arm9/main @ 0x0208AD68; symbol: func_0208ad68; size: 0x98.
extern "C" void ApplyPartyMemberCommandAndCompareRecordValue(unsigned char* command,int member) { GameState* state=GameState::GetInstance(); unsigned char* overlay=(unsigned char*)GameResources_GetInstance(); void* owner=*(void**)(overlay+0x36d0); Object* object=(Object*)state->GetPartyMemberByIndex(member); unsigned short before=object->record->value; GameObject_SubtractHPWithOptionalDeath(object,command[5],0); if(before!=object->record->value) {PartyStatus_SetMemberChangeAnimationEnabled(owner,member,1);PartyStatus_MarkMemberSnapshotChanged(owner,member);} if(Network_IsSessionActive(Network_GetConnectionManager()))Network_QueueCurrentPartyMemberState(member,1,0,1); }
