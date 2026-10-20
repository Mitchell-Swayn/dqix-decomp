#include <GameState/GameState.h>
#include <Resource/Brightness.h>
extern "C" { GameResources* GameState_ReadPResources(GameState*); void TextContext_GetSharedInstance(); }
// Original: arm9/ov008 @ 0x02186280; symbol: func_ov008_02186280; size: 0x44.
extern "C" void Graphics_SetBrightnessWhenOverlay8ByteB11IsZero(unsigned char* object) {
    GameResources* context=GameState_ReadPResources(GameState::GetInstance());
    TextContext_GetSharedInstance();
    if (object[0xb11] == 0) { SetBrightness(context,0,15); ++object[0xb11]; }
}
