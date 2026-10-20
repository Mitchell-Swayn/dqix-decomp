#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* GameState_ReadUnknownB0(void* state);
extern "C" int Input_TestKeyMask(unsigned short* keys, unsigned short mask);
extern "C" void Camera_EnableTargetFollowing(int object);
extern "C" void Camera_DisableTargetFollowing(int object);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov015 @ 0x021925A8; symbol: func_ov015_021925a8; size: 0x58.
extern "C" int CharacterViewer_UpdateCameraTargetFollowingFromInput(void) {
    void* state = _ZN9GameState11GetInstanceEv();
    if (state == 0)
        return 0;
    void* object = GameState_ReadUnknownB0(state);
    if (object == 0)
        return 0;
    if (Input_TestKeyMask(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0xc00)) {
        Camera_EnableTargetFollowing((int)object);
        return 1;
    }
    Camera_DisableTargetFollowing((int)object);
    return 0;
}
