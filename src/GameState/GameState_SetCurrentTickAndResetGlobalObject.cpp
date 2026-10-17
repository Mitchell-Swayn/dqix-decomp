#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" void* ReadWordFieldAtOffset1C();extern "C" void Object_ConfigureTextCountThroughEmbeddedHandler(void*,unsigned);extern "C" void func_020439b0(void*,int);
// Original: arm9/main @ 0x020D844C; symbol: func_020d844c; size: 0x38.
extern "C" ARM void GameState_SetCurrentTickAndResetGlobalObject(){GameState* s=GameState::GetInstance();void* p=ReadWordFieldAtOffset1C();Object_ConfigureTextCountThroughEmbeddedHandler(p,s->GetTickCount());func_020439b0(p,0);}
