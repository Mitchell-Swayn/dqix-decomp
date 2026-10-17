#pragma opt_propagation off
#pragma opt_arithtransformation off
#include <globaldefs.h>
#include "GameState/GameState.h"
struct Entry {unsigned char a,b,flags,pad;short value;char rest[14];};
struct Status {char pad[0x1c];unsigned char changed,dirty;char rest[2];};
extern "C" Entry data_020fdc60[];
extern "C" Status data_020fdcb0[];
extern "C" void* GetGlobalStatePointer();
extern "C" int TestWordMaskNonzero(void*,int);
extern "C" void func_020200c0(signed char,void*),UpdateUnlockedTimedValueByKind(Entry*,int),ResetModeDependentRecordValueAndCounter(Entry*),GameState_UpdateTimedValueTransition(Entry*,unsigned int,unsigned int);
struct Owner {char pad[0x558];unsigned char seen[4],unknown,active,pending;char gap[0x758-0x55f];unsigned char members[4],count;};
// Original: arm9/main @ 0x02026F34; symbol: func_02026f34; size: 0x1CC.
extern "C" ARM void GameState_UpdateFourPartyMemberEntryFlagsAndTimers(Owner* self) {
 if(!TestWordMaskNonzero(GetGlobalStatePointer(),0x41)) {
 GameState* state=GameState::GetInstance();unsigned int delta=state->GetEffectiveDeltaTime();
 for(int i=0;i<self->count;++i) {
  Entry* entry;Status* status;unsigned int mask;unsigned char member;unsigned int index;
  member=self->members[i];index=member;mask=(1<<index)&255;
  if(!(self->active&mask))continue;
  entry=data_020fdc60+i;status=data_020fdcb0+index;
  char* object=(char*)state->GetPartyMemberByIndex(index);if(!object)continue;
  int value=0;if(status->changed)value=2000;
  if(status->dirty || (self->pending&mask)) {func_020200c0((signed char)member,(char*)self+0xe8+index*0x28);self->pending&=~mask;}
  if(data_020fdc60[0].flags&2)ResetModeDependentRecordValueAndCounter(entry);
  else {
   if((entry->flags&1) && *(unsigned short*)(object+0x1b2)==0) {entry->flags&=~1;entry->value=2000;}
   else {
    if(*(unsigned short*)(object+0x1b2)!=0) {ResetModeDependentRecordValueAndCounter(entry);entry->flags|=1;}
    else if(value>0 && self->seen[index])UpdateUnlockedTimedValueByKind(entry,value);
   }
  }
  GameState_UpdateTimedValueTransition(entry,delta,index);if(status->changed)self->seen[index]=1;status->dirty=0;status->changed=0;
 }
 }
}
