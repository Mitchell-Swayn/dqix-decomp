#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
unsigned long long _Z19GetCurrentTimestampv();
void SleepOrCycleCurrentContextFromSharedState();
void System_ValidateAndApplyContextPair(void*,unsigned,void*,unsigned,void*,int);
struct Globals {char pad[0x48];int(*active)();};extern Globals data_ov031_0224c980;
}
struct State {char pad[8];unsigned char type;char pad9[0x1f];unsigned current;unsigned short pending,pad2e;unsigned completed,retries;};
// Original: arm9/ov031 @ 0x022037A8; symbol: func_ov031_022037a8; size: 0x208.
extern "C" unsigned Network_SendTwoBuffersWithTimeout(char* first,unsigned firstSize,char* second,unsigned secondSize,State* state){
unsigned total=0;
unsigned progress;int start;
int finalWait=0;
state->retries=0;
int last=(int)(_Z19GetCurrentTimestampv()>>16);
while(data_ov031_0224c980.active() && firstSize && state->type==4 && (int)((int)(_Z19GetCurrentTimestampv()>>16)-last)<159){
unsigned old=state->current;
System_ValidateAndApplyContextPair(first,firstSize,second,secondSize,state,finalWait);
start=(int)(_Z19GetCurrentTimestampv()>>16);
do{SleepOrCycleCurrentContextFromSharedState();}
while(data_ov031_0224c980.active() && state->type==4 && state->current!=state->completed && (int)((int)(_Z19GetCurrentTimestampv()>>16)-start)<15 && (!finalWait || !state->pending));
progress=state->completed-old;
if(progress>state->current-old)progress=0;
total+=progress;
if(progress)last=(int)(_Z19GetCurrentTimestampv()>>16);
state->current=state->completed;
if(state->type==4 && !state->pending && !progress){
if(!finalWait){
int startWait=(int)(_Z19GetCurrentTimestampv()>>16);
while(data_ov031_0224c980.active() && (int)((int)(_Z19GetCurrentTimestampv()>>16)-startWait)<15){
SleepOrCycleCurrentContextFromSharedState();if(state->pending)break;
}
if(!state->pending)finalWait=1;
}
}else finalWait=0;
if(progress<firstSize){first+=progress;firstSize-=progress;}
else{unsigned extra=progress-firstSize;first=second+extra;firstSize=secondSize-extra;second=0;secondSize=0;}
}
return total;
}
