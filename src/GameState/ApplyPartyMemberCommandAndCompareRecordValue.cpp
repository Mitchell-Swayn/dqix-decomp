#include <globaldefs.h>
ARM
#include "GameState/GameState.h"
extern "C" int SubtractLinkedHalfwordCountWithOptionalEmptyState(void*,int,int); extern "C" void WriteIndexedField558Boolean(void*,int,int); extern "C" void SetGlobalRecordStrideThirtyTwoFirstByte(void*,int); extern "C" void* Object_GetGlobalConnectionState(); extern "C" bool IsFirstWordNonzero(void*); extern "C" void QueueCharacterStatePacketTypeFour(int,int,int,int);
struct Record { unsigned char pad[4]; unsigned short value; }; struct Object { unsigned char pad[0x130]; Record* record; };
// Original: arm9/main @ 0x0208AD68; symbol: func_0208ad68; size: 0x98.
extern "C" void ApplyPartyMemberCommandAndCompareRecordValue(unsigned char* command,int member) { GameState* state=GameState::GetInstance(); unsigned char* overlay=(unsigned char*)GameResources_GetInstance(); void* owner=*(void**)(overlay+0x36d0); Object* object=(Object*)state->GetPartyMemberByIndex(member); unsigned short before=object->record->value; SubtractLinkedHalfwordCountWithOptionalEmptyState(object,command[5],0); if(before!=object->record->value) {WriteIndexedField558Boolean(owner,member,1);SetGlobalRecordStrideThirtyTwoFirstByte(owner,member);} if(IsFirstWordNonzero(Object_GetGlobalConnectionState()))QueueCharacterStatePacketTypeFour(member,1,0,1); }
