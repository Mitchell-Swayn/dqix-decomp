#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" int func_02067fec(int,BaseCombatStats*,void*);
// Original: arm9/main @ 0x020689A4; symbol: func_020689a4; size: 0x40.
extern "C" bool GameState_TestFirstPartyMemberStatsPredicate(GameState* state,int unused,void* out){GameObject* obj=state->GetPartyMemberByIndex(0);if(!obj)return false;return func_02067fec(0,obj->baseStats_,out)==0;}
