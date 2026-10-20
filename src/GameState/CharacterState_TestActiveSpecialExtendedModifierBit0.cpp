#include <globaldefs.h>
struct State{char pad[0x2ac];short count;char gap[0x4a];unsigned enabled:1;unsigned other:31;};

#pragma optimization_level 4
// Original: arm9/main @ 0x02085768; symbol: func_02085768; size: 0x2C.
extern "C" ARM bool CharacterState_TestActiveSpecialExtendedModifierBit0(State* p){if(p->count<=0)return false;return p->enabled!=0;}
