#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" void* TextContext_GetSharedInstance();extern "C" void TextWindow_AdvanceTextForRequestedTicks(void*,unsigned);extern "C" void TextWindow_RenderAndTransferDisplayBuffers(void*,int);
// Original: arm9/main @ 0x020D844C; symbol: func_020d844c; size: 0x38.
extern "C" ARM void GameState_SetCurrentTickAndResetGlobalObject(){GameState* s=GameState::GetInstance();void* p=TextContext_GetSharedInstance();TextWindow_AdvanceTextForRequestedTicks(p,s->GetTickCount());TextWindow_RenderAndTransferDisplayBuffers(p,0);}
