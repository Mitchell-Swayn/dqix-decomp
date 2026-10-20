#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameResources_GetInstance();
extern "C" void Graphics_ReleaseSelectionResourcesAndClearMainBG(void*);
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void GameObject_RequestMovementInputEnable(void*);
extern "C" void* GameState_GetFieldOrbitCamera(void*);
extern "C" void Camera_EnableOrbitInput(void*);
extern "C" void Camera_ClearFollowControlFlags(unsigned char*, unsigned char);
extern "C" void GameResources_ClearSecondaryFlags(int, unsigned);
// Original: arm9/ov003 @ 0x0217F1B8; symbol: func_ov003_0217f1b8; size: 0x60.
extern "C" ARM void Ov003_CompleteSelectionInitialization(void* object) {
    void* state = _ZN9GameState11GetInstanceEv();
    void* resources = GameResources_GetInstance();
    Graphics_ReleaseSelectionResourcesAndClearMainBG(object);
    GameObject_RequestMovementInputEnable(_ZN9GameState20GetUnknownGameObjectEv(state));
    void* target = GameState_GetFieldOrbitCamera(state);
    Camera_EnableOrbitInput(target);
    Camera_ClearFollowControlFlags((unsigned char*)target, 2);
    GameResources_ClearSecondaryFlags((int)resources, 0xc0);
    *((unsigned char*)object + 1) = 1;
}
