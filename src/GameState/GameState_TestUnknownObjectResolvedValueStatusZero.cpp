#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" int func_02067fec(int,void*,unsigned);
// Original: arm9/main @ 0x02068A20; symbol: func_02068a20; size: 0x3C.
extern "C" ARM bool GameState_TestUnknownObjectResolvedValueStatusZero(GameState* game,unsigned unused,unsigned value){void* object=game->GetUnknownGameObject();if(!object)return false;return func_02067fec(0,*(void**)((char*)object+0x134),value)==0;}
