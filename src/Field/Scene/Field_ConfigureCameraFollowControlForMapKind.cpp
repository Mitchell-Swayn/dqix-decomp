#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
struct CameraMapDescriptor {
    unsigned char unknown_00[12];
    unsigned char kind : 4;
    unsigned char reserved : 3;
    unsigned char followDisabled : 1;
};
extern "C" void* GameState_GetFieldOrbitCamera(GameState*);
extern "C" void Camera_SetFollowControlFlags(void*, unsigned char);
extern "C" void Camera_ClearFollowControlFlags(void*, unsigned char);
extern "C" void Camera_IgnoreOrbitInputModeRequest(void*, int);
#pragma force_active on
// Original: arm9/ov017 @ 0x0219E234; symbol: func_ov017_0219e234; size: 0x5C.
extern "C" void Field_ConfigureCameraFollowControlForMapKind(void*, int, int, const CameraMapDescriptor* map) {
    void* camera = GameState_GetFieldOrbitCamera(GameState::GetInstance());
    if (!camera) return;
    if (!map->kind || !map->followDisabled) {
        Camera_SetFollowControlFlags(camera, 0x10);
        Camera_IgnoreOrbitInputModeRequest(camera, 2);
    } else {
        Camera_ClearFollowControlFlags(camera, 0x10);
    }
}

#pragma force_active off
