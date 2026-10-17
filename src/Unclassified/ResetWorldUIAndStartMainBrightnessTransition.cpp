#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
struct GameResources;
extern "C" void ReadWordFieldAtOffset1C(void);
extern "C" void ResetGlobalOwnerAndEmbeddedSelectionState(void);
class GameState { public: static GameState *GetInstance(); };
extern "C" void GameState_GetField3B0ObjectWithFlag4(void);
extern "C" void ResetInterpolationAndDispatchStoredHalfwordValue(void);
extern "C" GameResources *GameResources_GetInstance(void);
extern void SetMainBrightness(GameResources *, int, int);
extern "C" void ClearFlagAndPopOverlaySlot(unsigned int);
// Original: arm9/main @ 0x020E4524; symbol: func_020e4524; size: 0x38.
extern "C" void ResetWorldUIAndStartMainBrightnessTransition(unsigned int param_1) {
    ReadWordFieldAtOffset1C();
    ResetGlobalOwnerAndEmbeddedSelectionState();
    GameState::GetInstance();
    GameState_GetField3B0ObjectWithFlag4();
    ResetInterpolationAndDispatchStoredHalfwordValue();
    GameResources *resources = GameResources_GetInstance();
    SetMainBrightness(resources, 0, 0x3c);
    ClearFlagAndPopOverlaySlot(param_1);
}
