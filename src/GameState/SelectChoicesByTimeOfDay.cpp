#include <globaldefs.h>
#pragma optimize_for_size on
#pragma opt_dead_assignments off
#include <GameState/GameState.h>
struct Choice {unsigned short id,pad;unsigned time:3;unsigned gap:10;unsigned mask:8;unsigned remaining:11;};
extern "C" int ReadWordAtOffsetC0(void*);
extern "C" Choice* Object_GetThirtyTwoByteEntryBelowCount(void*,int);
extern "C" void* FindThirtyTwoByteRecordByHalfwordKey(void*,unsigned);
extern "C" int ComputeRandomScaledIntegerThroughDouble(int);
// Original: arm9/main @ 0x02073EC4; symbol: func_02073ec4; size: 0x118.
extern "C" ARM void* SelectChoicesByTimeOfDay(unsigned mask,void* choices) {
 unsigned selected[6];
 unsigned fallback[6];
 GameState* state=GameState::GetInstance();
 int selectedCount=0;
 int fallbackCount=0;
 int i;
 for(i=0;i<ReadWordAtOffsetC0(choices);++i){
  Choice* entry=Object_GetThirtyTwoByteEntryBelowCount(choices,i);
  if(entry && (entry->time!=0 || state->GetTimeOfDay()!=0) && (entry->time!=1 || state->GetTimeOfDay()==0)){
   unsigned short id=entry->id;
   unsigned restriction=entry->mask;
   fallback[fallbackCount++]=id;
   if(!restriction || (restriction&mask))selected[selectedCount++]=id;
  }
 }
 void* result;
 if(!selectedCount){
  if(!fallbackCount)result=0;
  else {
   unsigned id=fallback[ComputeRandomScaledIntegerThroughDouble(fallbackCount)];
   result=FindThirtyTwoByteRecordByHalfwordKey(choices,id);
  }
 } else {
  unsigned id=selected[ComputeRandomScaledIntegerThroughDouble(selectedCount)];
  result=FindThirtyTwoByteRecordByHalfwordKey(choices,id);
 }
 return result;
}
