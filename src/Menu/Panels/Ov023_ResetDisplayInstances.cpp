#include <globaldefs.h>
extern "C" void CharacterPreview_ResetModelsAndReleaseAllocators(void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetFieldOrbitCamera(void*);
extern "C" void Camera_EnableTargetFollowing(void*);
extern "C" void Camera_SetProjectionAngle(void*, unsigned);
// Original: arm9/ov023 @ 0x021FC6CC; symbol: func_ov023_021fc6cc; size: 0x50.
extern "C" ARM void Ov023_ResetDisplayInstances(void* object) {
    for (int i = 0; i < 2; ++i)
        CharacterPreview_ResetModelsAndReleaseAllocators((char*)object + 0x20 + i * 0xc20);
    void* target = GameState_GetFieldOrbitCamera(_ZN9GameState11GetInstanceEv());
    Camera_EnableTargetFollowing(target);
    unsigned angle = *(unsigned*)((char*)object + 0x1860);
    Camera_SetProjectionAngle(target, angle);
}
