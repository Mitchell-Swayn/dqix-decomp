#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *_ZN9GameState20GetUnknownGameObjectEv(void *);
extern "C" void GameObject_RequestMovementInputEnable(void *);
extern "C" void GameObject_CancelTargetMovement(void *);
extern "C" void GameObject_SetMotionState(void *, int);
extern "C" void *GameResources_GetInstance(void);
extern "C" void *GameState_GetFieldOrbitCamera(void *);
extern "C" void Camera_EnableOrbitInput(void *);
extern "C" void GameResources_ClearSecondaryFlags(void *, unsigned int);
// Original: arm9/ov017 @ 0x021BFF2C; symbol: func_ov017_021bff2c; size: 0x60.
extern "C" void GameState_ResetUnknownObjectAndResourceFlag(void) {
    void *state = _ZN9GameState11GetInstanceEv();
    void *object = _ZN9GameState20GetUnknownGameObjectEv(state);
    GameObject_RequestMovementInputEnable(object);
    GameObject_CancelTargetMovement(object);
    GameObject_SetMotionState(object, 0);
    void *resources = GameResources_GetInstance();
    void *flagged = GameState_GetFieldOrbitCamera(state);
    if (flagged != 0) Camera_EnableOrbitInput(flagged);
    if (resources != 0) GameResources_ClearSecondaryFlags(resources, 0x80);
}
