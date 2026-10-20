#include <globaldefs.h>
ARM
#include "GameState/GameState.h"
extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x020AC0B4; symbol: func_020ac0b4; size: 0x28.
 extern "C" int GameState_CopyAlchemyOperationCount(void* dest) { GameState* state=GameState::GetInstance();memcpy(dest,(unsigned char*)state+0x7ac0,4);return 1; }
