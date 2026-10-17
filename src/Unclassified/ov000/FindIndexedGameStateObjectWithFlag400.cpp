#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameObject* GameState_FindIndexedObjectWithFlag400(GameState*,int);
#pragma force_active on
// Original: arm9/ov000 @ 0x021536F8; symbol: func_ov000_021536f8; size: 0x18.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" GameObject* FindIndexedGameStateObjectWithFlag400(void*, int index)
{
    return GameState_FindIndexedObjectWithFlag400(GameState::GetInstance(), index);
}
