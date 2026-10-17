#include <globaldefs.h>
struct State{char pad[32];unsigned mode:2;unsigned middle:3;unsigned enabled:1;unsigned rest:26;};struct Owner{char pad[0x13c];State* state;};extern "C" void Object3D_MoveToSelectedLocationAndResetAnimation(Owner*,int);
#pragma optimization_level 4
// Original: arm9/main @ 0x02049E88; symbol: func_02049e88; size: 0x38.
extern "C" ARM void Object_ResetNestedModeAndEnableState(Owner* p){if(!p->state)return;p->state->mode=0;p->state->enabled=1;Object3D_MoveToSelectedLocationAndResetAnimation(p,0);}
