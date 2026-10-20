#include <globaldefs.h>
#pragma optimize_for_size on
#pragma opt_dead_assignments off
#include <GameState/GameState.h>
struct Choice {unsigned short id,pad;unsigned time:3;unsigned gap:10;unsigned mask:8;unsigned remaining:11;};
extern "C" int Actor_GetChoiceCount(void*);
extern "C" Choice* Actor_GetChoiceByIndex(void*,int);
extern "C" void* Actor_FindChoiceById(void*,unsigned);
extern "C" int Random_ScaleIntegerByRandFraction(int);
// Original: arm9/main @ 0x02073EC4; symbol: func_02073ec4; size: 0x118.
extern "C" ARM void* SelectChoicesByTimeOfDay(unsigned mask,void* choices) {
 unsigned selected[6];
 unsigned fallback[6];
 GameState* state=GameState::GetInstance();
 int selectedCount=0;
 int fallbackCount=0;
 int i;
 for(i=0;i<Actor_GetChoiceCount(choices);++i){
  Choice* entry=Actor_GetChoiceByIndex(choices,i);
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
   unsigned id=fallback[Random_ScaleIntegerByRandFraction(fallbackCount)];
   result=Actor_FindChoiceById(choices,id);
  }
 } else {
  unsigned id=selected[Random_ScaleIntegerByRandFraction(selectedCount)];
  result=Actor_FindChoiceById(choices,id);
 }
 return result;
}
