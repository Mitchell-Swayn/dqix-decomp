#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameResources_GetInstance(void);
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" void *GameState_GetFieldOrbitCamera(void *);
extern "C" void Camera_EnableOrbitInput(void *);
extern "C" int _Z21IsGrottoBossFloorZonei(int);
extern "C" void StoreModeTimestampAndDisableTwoInputOwners(unsigned);
// Original: arm9/ov017 @ 0x021A9FA0; symbol: func_ov017_021a9fa0; size: 0x4C.
extern "C" void GameState_ApplyConditionalModeState(void *obj) {
    void *state = _ZN9GameState11GetInstanceEv();
    GameResources_GetInstance();
    unsigned short *global = (unsigned short *)Zone3D_GetMainInstance();
    Camera_EnableOrbitInput(GameState_GetFieldOrbitCamera(state));
    if (_Z21IsGrottoBossFloorZonei(*global)) StoreModeTimestampAndDisableTwoInputOwners(1000);
    *((unsigned char *)obj + 1) = 1;
}
