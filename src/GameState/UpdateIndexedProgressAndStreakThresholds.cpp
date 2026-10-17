#pragma opt_propagation off
#pragma opt_arithtransformation off
#include <globaldefs.h>
#include "GameState/GameState.h"
struct Context {virtual int Test(unsigned int,void*)=0;virtual void Done(unsigned int)=0;unsigned char pad[2],limit,progress[17],streak[4];};
extern "C" unsigned char data_020e8cc5[],data_020e8cc6[];
struct State {char pad[0xf78];unsigned char indices[4],count;};
extern "C" State* GameState_GetIndexList(GameState*);
extern "C" void* Object_GetGlobalConnectionState(),*ReadGlobalValueAt02153637();
extern "C" int IsFirstWordNonzero(void*),ClassifyContextIdStateAndEntryOwnership(void*,int);
extern "C" void RecordArray_SetFirstEmptyFlagWhenModeEnabled(void*,int),RecordArray_ClearMatchingCurrentOwnerEntry(void*,int),DispatchTwoValuesWithActiveByteMode(void*,int),Object_ApplyGlobalRecordAndPlayEffect120(Context*);
// Original: arm9/main @ 0x0208AB34; symbol: func_0208ab34; size: 0x1E8.
extern "C" ARM void UpdateIndexedProgressAndStreakThresholds(Context* self,void* argument) {
 State* state=GameState_GetIndexList(GameState::GetInstance());void* mode=Object_GetGlobalConnectionState();
 bool completed=false;int reset=0;void* trigger=ReadGlobalValueAt02153637();
 for(int i=0;i<state->count;++i) {
  int status=ClassifyContextIdStateAndEntryOwnership(trigger,1);unsigned int index=state->indices[i];
  if((!IsFirstWordNonzero(mode) || (IsFirstWordNonzero(mode) && status!=1)) && !self->Test(index,argument)) {
   for(int j=0;j<3;++j)if(self->streak[index]==data_020e8cc5[j*2])self->progress[index]+=data_020e8cc6[j*2];
   self->streak[index]=0;
  }else {
   if(self->limit<=self->progress[index]) {
    if(status!=2 && status!=1)RecordArray_SetFirstEmptyFlagWhenModeEnabled(trigger,1);
    if(status==1) {self->progress[index]=0;reset=1;if(self->Test(index,argument)){completed=true;self->Done(index);}}
    else if((unsigned int)(status-3)<=2)RecordArray_ClearMatchingCurrentOwnerEntry(trigger,1);
   }else {++self->progress[index];if(self->streak[index]<255)++self->streak[index];}
  }
 }
 if(completed)Object_ApplyGlobalRecordAndPlayEffect120(self);if(reset)DispatchTwoValuesWithActiveByteMode(trigger,1);
}
