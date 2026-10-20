#include <globaldefs.h>
ARM
extern "C" void* _Z11GetBTRandomv();
extern "C" int _Z17NextRandomBetweenP6Randomii(void*,int,int);
struct State {unsigned char pad[0x773c];signed char ids[4];signed char timers[4];};
// Original: arm9/ov000 @ 0x021637FC; symbol: func_ov000_021637fc; size: 0x98.
extern "C" int GameState_QueueFourSlotObjectCountdown(State* p,int index){
 int i;
 if(index<0 || index>=4)return 0;
 int previous=-1;
 for(i=0;i<4;i++){
 if(p->ids[i]<0){
 p->ids[i]=index;
 void* random=_Z11GetBTRandomv();
 int delay;
 if(previous<0)delay=0;
 else delay=previous+_Z17NextRandomBetweenP6Randomii(random,3,10);
 p->timers[i]=delay;
 return 1;
 }
 previous=p->timers[i];
 }
 return 0;
}
