#pragma opt_rebuildlogicals off
#pragma opt_optimizecontrolflow off
#pragma always_inline on
#include <globaldefs.h>
ARM
extern "C" void Alltrades_CancelVocationPreviewLoads(void*);
extern "C" int Alltrades_IsVocationPreviewReady(unsigned char*);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void SystemState_ClearFlags(unsigned int*,unsigned int);
extern "C" void ComputeGrottoAndContextDependentStateFlags(int);
inline bool IsSelectedStateInFirstFour(int selected) {return selected>=0 && selected<=3;}
// Original: arm9/ov003 @ 0x02158184; symbol: func_ov003_02158184; size: 0x90.
extern "C" void BackgroundLoader_AdvanceCancellationAndFinishState(unsigned char* self) {
 int phase=self[0x1f9];
 unsigned char* state=*(unsigned char**)(self+4);
 if(phase==0) {
  int selected=*(signed char*)(state+0x59);
  int valid=IsSelectedStateInFirstFour(selected);
  if(!valid) {self[0x1f8]=7;return;}
  *(signed char*)(state+0x59)=-1;
  Alltrades_CancelVocationPreviewLoads(state);
  self[0x1f9]++;
 } else if(phase==1) {
  if(!Alltrades_IsVocationPreviewReady(state)) return;
  SystemState_ClearFlags((unsigned int*)SystemState_GetGlobalFlags(),1);
  ComputeGrottoAndContextDependentStateFlags(0);
  self[0x1f8]=7;
 }
}
