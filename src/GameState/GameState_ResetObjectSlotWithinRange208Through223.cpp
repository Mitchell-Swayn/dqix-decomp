#include <globaldefs.h>
ARM
#include "GameState/GameState.h"
extern "C" void GameState_ClearObjectByIndex(GameState*,int);
// Original: arm9/main @ 0x02057DB8; symbol: func_02057db8; size: 0x28.
 extern "C" void GameState_ResetObjectSlotWithinRange208Through223(void*,int index) { if (index<0xd0) return; if (index>0xdf) return; GameState_ClearObjectByIndex(GameState::GetInstance(),index); }
