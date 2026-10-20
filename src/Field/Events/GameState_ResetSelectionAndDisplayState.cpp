#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned int TextContext_GetSharedInstance(void *);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void *);
extern "C" unsigned int DisplayContext_GetGlobalInstance(void);
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(int);
extern "C" void *GameResources_GetInstance(void);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void *, int, int);
extern "C" void *_ZN9GameState20GetUnknownGameObjectEv(void *);
extern "C" void GameObject_RequestMovementInputEnable(void *);
extern "C" void GameState_ApplyConditionalModeState(void *);
// Original: arm9/ov017 @ 0x021A9F58; symbol: func_ov017_021a9f58; size: 0x48.
extern "C" void GameState_ResetSelectionAndDisplayState(void *obj) {
    void *state = _ZN9GameState11GetInstanceEv();
    TextWindow_ResetGlyphBuffersAndFrameContexts((void *)TextContext_GetSharedInstance(state));
    BackgroundLoader_CancelEightTasksAndResetState((int)DisplayContext_GetGlobalInstance());
    _Z17SetMainBrightnessP13GameResourcesii(GameResources_GetInstance(), 0, 0x14);
    GameObject_RequestMovementInputEnable(_ZN9GameState20GetUnknownGameObjectEv(state));
    GameState_ApplyConditionalModeState(obj);
}
