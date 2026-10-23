#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
#include <World/Zone3D.h>
extern "C" {
Zone3D* Zone3D_GetMainInstance();
void* GameState_GetFieldOrbitCamera(GameState*);
int ZoneFeatures_TestPointInsideEntry(ZoneFeatures::Opcode6aEntry*,const Vector3fix*);
int Camera_IsRecentering(void*);
void Camera_SetRecentering(void*, int);
void Camera_SetPlaneBlendForActionFour(void*, const void*);
void Camera_SetPlaneBlendForActionFive(void*, const void*);
void Camera_IgnoreRegionAction(void*, unsigned, const void*, const void*);
void Camera_DisableRegionOrbitInput(void*);
void Camera_EnableRegionOrbitInput(void*);
void Camera_ClearRegionMotionState(void*);
void Camera_DisablePlaneBlend(void*);
}
#pragma force_active on
// Original: arm9/ov017 @ 0x021982AC; symbol: func_ov017_021982ac; size: 0x134.
// Applies the first containing type-four region to the field camera.
extern "C" void Field_ApplyContainingCameraRegion() {
    GameState* game = GameState::GetInstance();
    Zone3D* zone = Zone3D_GetMainInstance();
    Vector3fix position = game->GetUnknownGameObject()->obj3D_.position_;
    ZoneFeatures::Opcode6aEntry* region = zone->bFeatures_.GetTypeEntries(4);
    void* camera = GameState_GetFieldOrbitCamera(game);
    if (!camera) return;
    int planeBlend = 0;
    for (; region; region = region->pNext) {
        if (ZoneFeatures_TestPointInsideEntry(region, &position)) {
            unsigned action = region->unk_2c.type4.unk_0;
            if (action == 4) {
                if (Camera_IsRecentering(camera)) Camera_SetRecentering(camera, 0);
                Camera_SetPlaneBlendForActionFour(camera, &region->unk_2c.type4.vector_4);
                planeBlend = 1;
            } else if (action == 5) {
                Camera_SetPlaneBlendForActionFive(camera, &region->unk_2c.type4.vector_4);
                planeBlend = 1;
            } else {
                Camera_IgnoreRegionAction(camera, action, &region->unk_2c.type4.vector_4, &region->unk_2c.type4.vector_30);
            }
            if (!region->unk_2c.type4.unk_0_high) Camera_DisableRegionOrbitInput(camera);
            break;
        }
    }
    if (!region) {
        Camera_EnableRegionOrbitInput(camera);
        Camera_ClearRegionMotionState(camera);
    }
    if (!planeBlend) Camera_DisablePlaneBlend(camera);
}
#pragma force_active off
