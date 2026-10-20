#pragma opt_propagation off
#pragma opt_arithtransformation off
#include <globaldefs.h>
#include "GameState/GameState.h"
struct Context {virtual int Test(unsigned int,void*)=0;virtual void Done(unsigned int)=0;unsigned char pad[2],limit,progress[17],streak[4];};
// Original data: arm9/main @ 0x20e8cc5; symbol: data_020e8cc5.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e8cc6; symbol: data_020e8cc6.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 040202030100cdcc4c3e.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char UpdateIndexedProgressAndStreakThresholds_UnknownRoleInitializedBytes[],UpdateIndexedProgressAndStreakThresholds_UnknownRoleInitializedBytes_Variant2[];
struct State {char pad[0xf78];unsigned char indices[4],count;};
extern "C" State* GameState_GetIndexList(GameState*);
extern "C" void* Network_GetConnectionManager(),*NetworkOwnership_GetRegistry();
extern "C" int Network_IsSessionActive(void*),NetworkOwnership_ClassifyLocalRequest(void*,int);
extern "C" void NetworkOwnership_QueueRequest(void*,int),NetworkOwnership_ClearLocalEntry(void*,int),NetworkOwnership_ReleaseForLocalPeer(void*,int),PartyProgress_PlayCompletionColorEffect(Context*);
// Original: arm9/main @ 0x0208AB34; symbol: func_0208ab34; size: 0x1E8.
extern "C" ARM void UpdateIndexedProgressAndStreakThresholds(Context* self,void* argument) {
 State* state=GameState_GetIndexList(GameState::GetInstance());void* mode=Network_GetConnectionManager();
 bool completed=false;int reset=0;void* trigger=NetworkOwnership_GetRegistry();
 for(int i=0;i<state->count;++i) {
  int status=NetworkOwnership_ClassifyLocalRequest(trigger,1);unsigned int index=state->indices[i];
  if((!Network_IsSessionActive(mode) || (Network_IsSessionActive(mode) && status!=1)) && !self->Test(index,argument)) {
   for(int j=0;j<3;++j)if(self->streak[index]==UpdateIndexedProgressAndStreakThresholds_UnknownRoleInitializedBytes[j*2])self->progress[index]+=UpdateIndexedProgressAndStreakThresholds_UnknownRoleInitializedBytes_Variant2[j*2];
   self->streak[index]=0;
  }else {
   if(self->limit<=self->progress[index]) {
    if(status!=2 && status!=1)NetworkOwnership_QueueRequest(trigger,1);
    if(status==1) {self->progress[index]=0;reset=1;if(self->Test(index,argument)){completed=true;self->Done(index);}}
    else if((unsigned int)(status-3)<=2)NetworkOwnership_ClearLocalEntry(trigger,1);
   }else {++self->progress[index];if(self->streak[index]<255)++self->streak[index];}
  }
 }
 if(completed)PartyProgress_PlayCompletionColorEffect(self);if(reset)NetworkOwnership_ReleaseForLocalPeer(trigger,1);
}
