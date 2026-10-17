#include <globaldefs.h>
ARM
#include <World/Object3D.h>
#include <GameState/GameState.h>
struct State{unsigned char pad[0x58];unsigned char package,animation,flags,pad5b;unsigned short timer;};
// Original: arm9/main @ 0x0204A054; symbol: func_0204a054; size: 0x74.
extern "C" void Object3D_ApplyAnimationWhenDelayExpires(Object3D* p){GameState* game=GameState::GetInstance();State* state=*(State**)((unsigned char*)p+0x13c);if(!state->timer)return;unsigned int dt=game->GetEffectiveDeltaTime();if(dt<state->timer){state->timer-=dt;return;}AnimationPackage* package=p->GetAnimationPackageByIndex(state->package);if(package){BCFG::AnimationRecord* record=package->bcfgData.GetAnimationRecord(state->animation);if(record)p->MaybeSetRegularAnimation((const char*)record,state->flags);}state->timer=0;}
