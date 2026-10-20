#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
struct GameResources;
extern "C" void TextContext_GetSharedInstance(void);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void);
class GameState { public: static GameState *GetInstance(); };
extern "C" void GameState_GetFieldOrbitCamera(void);
extern "C" void ResetInterpolationAndDispatchStoredHalfwordValue(void);
extern "C" GameResources *GameResources_GetInstance(void);
extern void SetMainBrightness(GameResources *, int, int);
extern "C" void Grotto_ReleaseMonsterMessageCommandAndRestoreOverlay(unsigned int);
// Original: arm9/main @ 0x020E4524; symbol: func_020e4524; size: 0x38.
extern "C" void Grotto_CloseMonsterMessageScene(unsigned int param_1) {
    TextContext_GetSharedInstance();
    TextWindow_ResetGlyphBuffersAndFrameContexts();
    GameState::GetInstance();
    GameState_GetFieldOrbitCamera();
    ResetInterpolationAndDispatchStoredHalfwordValue();
    GameResources *resources = GameResources_GetInstance();
    SetMainBrightness(resources, 0, 0x3c);
    Grotto_ReleaseMonsterMessageCommandAndRestoreOverlay(param_1);
}
