#include <globaldefs.h>
ARM
#include "GameState/GameState.h"
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
// Original: arm9/main @ 0x020A36A8; symbol: func_020a36a8; size: 0x24.
 extern "C" bool GameState_TestProtagonistIndexMatchesStoredByte(signed char* p) { GameState* state=GameState::GetInstance(); int index=GameState_ReadProtagonistObjectIndex(state); return p[0x2a]==index; }
