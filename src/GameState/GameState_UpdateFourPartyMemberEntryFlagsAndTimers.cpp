#pragma opt_propagation off
#pragma opt_arithtransformation off
#include <globaldefs.h>
#include "GameState/GameState.h"
struct Entry {unsigned char a,b,flags,pad;short value;char rest[14];};
struct Status {char pad[0x1c];unsigned char changed,dirty;char rest[2];};
// Original data: arm9/main @ 0x20fdc60; symbol: data_020fdc60.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Entry PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x20fdcb0; symbol: data_020fdcb0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Status GraphicsSelectObjectRatioColor_UnknownRoleZeroInitializedStorage[];
extern "C" void* SystemState_GetGlobalFlags();
extern "C" int SystemState_TestAnyFlags(void*,int);
extern "C" void PartyStatus_RenderMemberPortraitLabels(signed char,void*),UpdateUnlockedTimedValueByKind(Entry*,int),ResetModeDependentRecordValueAndCounter(Entry*),GameState_UpdateTimedValueTransition(Entry*,unsigned int,unsigned int);
struct Owner {char pad[0x558];unsigned char seen[4],unknown,active,pending;char gap[0x758-0x55f];unsigned char members[4],count;};
// Original: arm9/main @ 0x02026F34; symbol: func_02026f34; size: 0x1CC.
extern "C" ARM void GameState_UpdateFourPartyMemberEntryFlagsAndTimers(Owner* self) {
 if(!SystemState_TestAnyFlags(SystemState_GetGlobalFlags(),0x41)) {
 GameState* state=GameState::GetInstance();unsigned int delta=state->GetEffectiveDeltaTime();
 for(int i=0;i<self->count;++i) {
  Entry* entry;Status* status;unsigned int mask;unsigned char member;unsigned int index;
  member=self->members[i];index=member;mask=(1<<index)&255;
  if(!(self->active&mask))continue;
  entry=PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage+i;status=GraphicsSelectObjectRatioColor_UnknownRoleZeroInitializedStorage+index;
  char* object=(char*)state->GetPartyMemberByIndex(index);if(!object)continue;
  int value=0;if(status->changed)value=2000;
  if(status->dirty || (self->pending&mask)) {PartyStatus_RenderMemberPortraitLabels((signed char)member,(char*)self+0xe8+index*0x28);self->pending&=~mask;}
  if(PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage[0].flags&2)ResetModeDependentRecordValueAndCounter(entry);
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
