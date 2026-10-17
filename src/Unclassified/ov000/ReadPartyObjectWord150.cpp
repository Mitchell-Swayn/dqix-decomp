#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" int ReadWordFieldAtOffset150(GameObject*);
#pragma force_active on
// Original: arm9/ov000 @ 0x02153710; symbol: func_ov000_02153710; size: 0x48.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" int ReadPartyObjectWord150(void*, int index)
{
    int valid = index >= 0 && index <= 3; if (!valid) return 0; GameObject* p=GameState_GetObjectWithFlag100(GameState::GetInstance(),index); if (!p) return 0; return ReadWordFieldAtOffset150(p);
}
