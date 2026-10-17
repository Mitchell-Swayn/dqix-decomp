#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned int ReadWordFieldAtOffset1C(void *);
extern "C" void ResetGlobalOwnerAndEmbeddedSelectionState(void *);
extern "C" unsigned int Object_ReadGlobalDisplayContextWord(void);
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(int);
extern "C" void *GameResources_GetInstance(void);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void *, int, int);
extern "C" void *_ZN9GameState20GetUnknownGameObjectEv(void *);
extern "C" void SetByteFieldAtOffset253ToOne(void *);
extern "C" void func_ov017_021a9fa0(void *);
// Original: arm9/ov017 @ 0x021A9F58; symbol: func_ov017_021a9f58; size: 0x48.
extern "C" void func_ov017_021a9f58(void *obj) {
    void *state = _ZN9GameState11GetInstanceEv();
    ResetGlobalOwnerAndEmbeddedSelectionState((void *)ReadWordFieldAtOffset1C(state));
    BackgroundLoader_CancelEightTasksAndResetState((int)Object_ReadGlobalDisplayContextWord());
    _Z17SetMainBrightnessP13GameResourcesii(GameResources_GetInstance(), 0, 0x14);
    SetByteFieldAtOffset253ToOne(_ZN9GameState20GetUnknownGameObjectEv(state));
    func_ov017_021a9fa0(obj);
}
