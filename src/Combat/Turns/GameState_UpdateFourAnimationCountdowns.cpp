#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" void _ZN8Object3D18SetAnimationByNameEPKci(void*,const char*,int);
extern "C" char GameState_UpdateFourAnimationCountdowns_TextStart[];
struct AnimationState {unsigned char pad[0x773c];signed char ids[4];unsigned char timers[4];};
// Original: arm9/ov000 @ 0x02163928; symbol: func_ov000_02163928; size: 0x8C.
extern "C" void GameState_UpdateFourAnimationCountdowns(AnimationState* p){
 void* gs=_ZN9GameState11GetInstanceEv();
 for(int i=0;i<4;i++){
 int id=p->ids[i];if(id<0)continue;
 int remaining=p->timers[i]-1;
 if(remaining<=0){p->ids[i]=-1;void* obj=GameState_GetObjectWithFlag100(gs,id);if(obj)_ZN8Object3D18SetAnimationByNameEPKci(obj,GameState_UpdateFourAnimationCountdowns_TextStart,1);}
 else p->timers[i]=remaining;
 }
}
